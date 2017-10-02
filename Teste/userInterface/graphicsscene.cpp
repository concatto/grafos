#include "graphicsscene.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QTransform>
#include <QGraphicsView>
#include <QColor>
#include <QStringList>

GraphicsScene::GraphicsScene()
{
    setSceneRect(0, 0, 740, 340);
    curr_vertex = NULL;
    controle_aresta = false;
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
    QObject::connect(vertex, SIGNAL(drawEdge(Vertex*)), this, SLOT(drawEdge(Vertex*)));
    return true;
}

void GraphicsScene::removeVertex(Vertex *vertex)
{
    vertices.removeOne(vertex);
    removeItem(vertex);
    delete vertex;
}

void GraphicsScene::setLine( Vertex *item)
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
    vertices.front()->print();
}

void GraphicsScene::paintVertices(QVector<int> cores)
{
    QStringList list = QColor::colorNames();

    for(int i = 0; i < cores.size(); i++){
        qDebug()<<vertices[i]->getName()<<list[i]<<" - "<<cores[i];
    }

    qDebug()<<"----------";

    for(int i = 0; i < vertices.size(); i++){
       vertices[i]->setBrush(QBrush(QColor(list.at(cores[i] + 10))));
    }
}

void GraphicsScene::drawEdge(Vertex *vertex)
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
        addItem(curr_line);
        curr_line = NULL;
        controle_aresta = false;
        emit addConnection(curr_vertex->getName(), vertex->getName());
        curr_vertex = NULL;
    }
}
