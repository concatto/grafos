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
#include "selfloop.h"

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
    // Corrige os identificadores dos vértices para condizer com suas posições na lista
    for (int i = vertex->getId() + 1; i < vertices.size(); i++) {
        vertices[i]->setId(vertices[i]->getId() - 1);
    }

    vertices.removeOne(vertex);
    removeItem(vertex);
    delete vertex;
}

void GraphicsScene::createLine(Vertex *item, bool isDirected, bool isWeighted)
{
    // Create a graphical edge, giving feedback to the user.
    Edge e(isDirected, isWeighted);
    e.setV1(item);
    currentLine = new StraightEdge(e); // Stores a copy
    addItem(currentLine);
}

void GraphicsScene::finishConnectionCreation(int id1, int id2, int weight)
{
    Edge model = currentLine->getModel();
    model.setV1(vertices[id1]);
    model.setV2(vertices[id2]);
    model.setWeight(weight);
    currentLine->setModel(model);

    EdgeInterface* line = currentLine;

    if (id1 == id2) {
        // It's a self loop!
        line = new SelfLoop(model);
        removeItem(currentLine);
        addItem(line->getItem());
        delete currentLine; // Careful
    }

    vertices[id1]->addConnection(line);

    if (id1 != id2) { // No need to add twice if it's a self loop
        vertices[id2]->addConnection(line);
    }

    line->centralize();
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

void GraphicsScene::paintPath(QVector<Arco> path)
{

    QPen pen(Qt::blue, 4);

    for(Arco a: path){
        vertices[a.vorigem]->setPen(pen);
        vertices[a.vorigem]->paintEdge(a.vdestino);
        repaintViews();
        sleep(500);
    }

    vertices[path.back().vdestino]->setPen(pen);
}

void GraphicsScene::paintSequence(QVector<int> sequence) {
    for (int id : sequence) {
        vertices[id]->setPen(QPen(QBrush(Qt::magenta), 4));
        repaintViews();
        sleep(333);
    }
}

EdgeInterface* GraphicsScene::findLine(int id1, int id2)
{
    for (EdgeInterface* edge : vertices[id1]->getLines()) {
        Edge model = edge->getModel();

        // Talvez seja necessário realizar a comparação inversa eventualmente
        if (model.getV1()->getId() == id1 && model.getV2()->getId() == id2) {
            return edge;
        }
    }

    return nullptr;
}

Vertex* GraphicsScene::getVertex(int id)
{
    return vertices[id];
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
    if(currentLine != nullptr) {
        emit addConnection(currentLine->getModel().getV1()->getId(), vertex->getId());
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
        if (currentLine != nullptr) {
            removeCurrentLine();
        }

        resetControlVaraibles();
        emit resetCursor();
    }
}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (currentLine != nullptr) {
        Vertex* origin = currentLine->getModel().getV1();
        currentLine->setLine(QLineF(origin->getCenter(), event->scenePos()));
    }

    if (movingVertex != nullptr) {
        movingVertex->handleMoveEvent(event);
    }
}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        Vertex* v = findItem<Vertex>(event->scenePos());

        if (v != nullptr) {
            if(sourceVertex == nullptr){
                movingVertex = v;
                v->setPressed(true);
            }
        }
    }
}

void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        Vertex* v = findItem<Vertex>(event->scenePos());

        if (v != nullptr) {
            executeSecondClickAction(v);
        }

        if (movingVertex != nullptr) {
            movingVertex->setPressed(false);
            movingVertex = nullptr;
        }
    }
}

void GraphicsScene::removeCurrentLine()
{
    if (currentLine != nullptr) {
        removeItem(currentLine);
        delete currentLine;
        currentLine = nullptr;
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
