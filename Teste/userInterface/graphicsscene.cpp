#include "graphicsscene.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QTransform>
#include <QGraphicsView>
#include <QColor>
#include <QStringList>
#include <QStack>
#include <QInputDialog>
#include <QLineEdit>

GraphicsScene::GraphicsScene() : QGraphicsScene()
{
    setSceneRect(0, 0, 740, 340);
    curr_vertex = NULL;
    controle_aresta = false;
    controle_dijkstra = false;
}

bool GraphicsScene::addVertex(QString name, QPointF pos)
{
    for(Vertex *v: vertices){
        if(v->getName() == name){
            emit duplicatedVertex();
            return false;
        }
    }
    Vertex *vertex = new Vertex(50, name);
    vertex->setPos(pos);
    vertices.append(vertex);
    addItem(vertices.back());
    QObject::connect(vertex, SIGNAL(mousePressed(Vertex*)), this, SLOT(mousePressed(Vertex*)));
    return true;
}

void GraphicsScene::removeVertex(Vertex *vertex)
{
    vertices.removeOne(vertex);
    vertex->setId(vertex->getId() - 1);
    removeItem(vertex);
    delete vertex;
}

void GraphicsScene::setLine(Vertex *item)
{
//    line.setP1(item->pos());
    curr_vertex = item;
    controle_aresta = true;
    curr_line = new GraphicsLine();
    curr_line->setV1(curr_vertex);
    item->addConnection(curr_line, true);
}

void GraphicsScene::print()
{
    for(Vertex *v: vertices){
        qDebug()<<v->getId();
    }
}

void GraphicsScene::paintVertices(QVector<int> cores, QBrush *brush)
{

    if(brush != NULL){ // Reset colors
        for(Vertex *v: vertices){
            v->setPen(Qt::NoPen);
            v->setBrush(*brush);
            v->paintEdge();
        }
        return;
    }

    QStringList list = QColor::colorNames();

//    for(int i = 0; i < list.size(); i++){
//        qDebug()<<list[i]<<i;
//    }

//    qDebug()<<"----------";

    for(int i = 0; i < vertices.size(); i++){
       vertices[i]->setBrush(QBrush(QColor(list.at(cores[i] + 20))));
    }
}

void GraphicsScene::paintDijkstra(QStack<int> stack)
{
    while(!stack.isEmpty()){
        int vertice = stack.top();
        stack.pop();

        vertices[vertice]->setPen(QPen(QBrush(Qt::green), 4));

        if(stack.isEmpty())
            break;
        vertices[vertice]->paintEdge(stack.top());

    }

}

void GraphicsScene::setDijkstra(Vertex *item)
{
    curr_vertex = item;
    controle_dijkstra = true;
}

void GraphicsScene::mousePressed(Vertex *vertex)
{
    if(controle_aresta){
        curr_line->setV2(vertex);
        if(!vertex->addConnection(curr_line, false)){
            delete curr_line;
            curr_line = NULL;
            curr_vertex = NULL;
            controle_aresta = false;
            emit duplicatedEdge();
            return;
        }
        bool ok = false;
        QString text;
        while(text.isEmpty()){
            text = QInputDialog::getText(views().back(), tr("Peso da aresta"),
                                                 tr("Peso da aresta:"), QLineEdit::Normal,
                                                 "", &ok);
            if(!ok)
                return;
        }
        curr_line->setWeight(text.toInt());
        addItem(curr_line);
        controle_aresta = false;
        emit addConnection(curr_vertex->getId(), vertex->getId(), curr_line->getWeight());
        curr_line = NULL;
        curr_vertex = NULL;
    }else if(controle_dijkstra){
        emit performDijkstra(curr_vertex->getId(), vertex->getId());
        curr_vertex = NULL;
        controle_dijkstra = false;
    }
}

void GraphicsScene::sleep(int msec)
{
    if(msec <= 0){
        return;
    }

    #ifdef Q_OS_WIN
        Sleep(uint(msec));
    #else
        struct timespec ts = { msec / 1000, (msec % 1000) * 1000 * 1000 };
        nanosleep(&ts, NULL);
    #endif
}


void GraphicsScene::keyPressEvent(QKeyEvent *event)
{
    if(event->key() & Qt::Key_Escape){
        if(controle_aresta){
            curr_vertex->removeConnection(curr_line);
            delete curr_line;
            curr_line = NULL;
            curr_vertex = NULL;
            controle_aresta = false;
        }else if(controle_dijkstra){
            controle_dijkstra = false;
        }
    }

}
