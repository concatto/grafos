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
    addingEdge = false;
    performingDijkstra = false;
}

bool GraphicsScene::addVertex(QString name, QPointF pos)
{
    for(Vertex *v: vertices){
        if(v->getName() == name){
            emit duplicatedVertex();
            return false;
        }
    }
    Vertex *vertex = new Vertex(25, name);
    vertex->setPos(pos);
    vertices.append(vertex);
    addItem(vertices.back());
//    QObject::connect(vertex, SIGNAL(mousePressed(Vertex*)), this, SLOT(mousePressed(Vertex*)));
    return true;
}

void GraphicsScene::removeVertex(Vertex *vertex)
{
    vertices.removeOne(vertex);
    vertex->setId(vertex->getId() - 1);
    removeItem(vertex);
    delete vertex;
}

void GraphicsScene::createLine(Vertex *item, bool isWeighted)
{
    sourceVertex = item;
    addingEdge = true;
    currentLine = new GraphicsLine(isWeighted);
    currentLine->setV1(sourceVertex);
    addItem(currentLine);
    item->addConnection(currentLine);

    currentLine->setLine(QLineF(item->getCenter(), item->getCenter()));
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
            v->setPen(QPen());
            v->setBrush(*brush);
            v->paintEdge();
        }
        return;
    }

    int value = 359 / cores.size();
    QColor color;

//    for(int i = 0; i < list.size(); i++){
//        qDebug()<<list[i]<<i;
//    }

//    qDebug()<<"----------";

    for(int i = 0; i < vertices.size(); i++){
//       vertices[i]->setBrush(QBrush(QColor(list.at(cores[i] + 10))));
        vertices[i]->setBrush(color.fromHsv(value * cores[i], 255, 255, 255));
        vertices[i]->update();
    }
}

void GraphicsScene::paintDijkstra(QStack<int> stack)
{
    while(!stack.isEmpty()){
        int vertice = stack.top();
        stack.pop();

        vertices[vertice]->setPen(QPen(QBrush(Qt::green), 4));

        if(stack.isEmpty())
            return;
        vertices[vertice]->paintEdge(stack.top());

        views().front()->viewport()->repaint();
        sleep(500);
    }

}

void GraphicsScene::prepareDijkstra(Vertex *item)
{
    sourceVertex = item;
    performingDijkstra = true;
}

void GraphicsScene::executeSecondClickAction(Vertex *vertex)
{
    if(addingEdge){
        addLine(vertex);
        emit addConnection(sourceVertex->getId(), vertex->getId(), currentLine->getWeight());
    }else if(performingDijkstra){
        emit performDijkstra(sourceVertex->getId(), vertex->getId());
        performingDijkstra = false;
    }
    resetControlVaraibles();
    emit resetCursor();
}

void GraphicsScene::resetControlVaraibles()
{
    currentLine = nullptr;
    sourceVertex = nullptr;
    addingEdge = false;
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

void GraphicsScene::addLine(Vertex *vertex)
{
        currentLine->setV2(vertex);
        if(!vertex->addConnection(currentLine)){
            removeItem(currentLine);
            delete currentLine;
            emit duplicatedEdge();
            return;
        }
        bool ok = false;
        QString text;
        if (currentLine->isWeighted()) {
            while(text.isEmpty()){
                text = QInputDialog::getText(views().back(), tr("Peso da aresta"),
                                                     tr("Peso da aresta:"), QLineEdit::Normal,
                                                     "", &ok);
                if(!ok)
                    return;
            }
        } else {
            text = "1";
        }
        currentLine->setWeight(text.toInt());
}


void GraphicsScene::keyPressEvent(QKeyEvent *event)
{
    if(event->key() & Qt::Key_Escape){
        if(addingEdge){
            sourceVertex->removeConnection(currentLine);
            delete currentLine;
        }

        resetControlVaraibles();
        emit resetCursor();
    }
}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (currentLine != nullptr && sourceVertex != nullptr) {
        currentLine->setLine(QLineF(sourceVertex->getCenter(), event->scenePos()));
    }

    if (movingVertex != nullptr) {
        movingVertex->handleMoveEvent(event);
    }
}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Vertex* v = findVertex(event->scenePos());
    if (v != nullptr) {

        if(sourceVertex != nullptr){
            executeSecondClickAction(v);
        }else {
            movingVertex = v;
            v->setPressed(true);
        }

    }
}

void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Vertex* v = findVertex(event->scenePos());
    if (v != nullptr) {
        executeSecondClickAction(v);
    }

    if (movingVertex != nullptr) {
        movingVertex->setPressed(false);
        movingVertex = nullptr;
    }
}



Vertex* GraphicsScene::findVertex(const QPointF& point)
{
    QGraphicsItem* item = itemAt(point, QTransform());
    if (item != nullptr && item->type() == Vertex::Type) {
        return static_cast<Vertex*>(item);
    }
    return nullptr;
}
