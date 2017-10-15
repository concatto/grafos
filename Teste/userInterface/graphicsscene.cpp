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
#include <iostream>

GraphicsScene::GraphicsScene() : QGraphicsScene()
{
    setSceneRect(0, 0, 740, 340);
    addingEdge = false;
    performingDijkstra = false;
}

bool GraphicsScene::addVertex(QString name, QPointF pos)
{
    float radius = 25;
    Vertex *vertex = new Vertex(radius, name);
    vertex->setPos(pos - QPointF(radius, radius));
    vertex->setId(vertices.size());
    vertices.append(vertex);
    addItem(vertices.back());
    return true;
}

void GraphicsScene::removeVertex(Vertex *vertex)
{
    for (int i = vertex->getId() + 1; i < vertices.size(); i++) {
        vertices[i]->setId(vertices[i]->getId() - 1);
    }

    vertices.removeOne(vertex);
    removeItem(vertex);
    delete vertex;
}

void GraphicsScene::createLine(Vertex *item, bool isWeighted)
{
    sourceVertex = item;
    addingEdge = true;
    currentLine = new GraphicsLine(isWeighted);
    currentLine->setV1(item);
    addItem(currentLine);
    item->addConnection(currentLine);

    currentLine->setLine(QLineF(item->getCenter(), item->getCenter()));
}

void GraphicsScene::finishConnectionCreation(int id1, int id2, int weight)
{
    currentLine->setV2(vertices[id2]);
    currentLine->setWeight(weight);
    vertices[id2]->addConnection(currentLine);
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

    int value = 360 / cores.size();
    QColor color;

//    for(int i = 0; i < list.size(); i++){
//        qDebug()<<list[i]<<i;
//    }

//    qDebug()<<"----------";

    for(int i = 0; i < vertices.size(); i++){
//       vertices[i]->setBrush(QBrush(QColor(list.at(cores[i] + 10))));
        vertices[i]->setBrush(color.fromHsv(value * cores[i], 255, 255, 255));
        qDebug() << cores[i] << ": " << value * cores[i];
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

        repaintViews();
        sleep(500);
    }

}

void GraphicsScene::paintSequence(QVector<int> sequence) {
    for (int id : sequence) {
        vertices[id]->setPen(QPen(QBrush(Qt::magenta), 4));
        repaintViews();
        sleep(333);
    }
}

void GraphicsScene::repaintViews()
{
    for (QGraphicsView* view : views()) {
        view->viewport()->repaint();
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
        emit addConnection(sourceVertex->getId(), vertex->getId());
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
    Vertex* v = findItem<Vertex>(event->scenePos());
    if (v != nullptr) {
        if(sourceVertex == nullptr){
            movingVertex = v;
            v->setPressed(true);
        }

    }
}

void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Vertex* v = findItem<Vertex>(event->scenePos());
    if (v != nullptr) {
        executeSecondClickAction(v);
    }

    if (movingVertex != nullptr) {
        movingVertex->setPressed(false);
        movingVertex = nullptr;
    }
}

int GraphicsScene::getTypeOfItemAt(QPointF point)
{
    QGraphicsItem* item = itemAt(point, QTransform());
    if (item != nullptr) {
        return item->type();
    }
    return -1;
}
