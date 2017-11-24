#include "graphicsscene.h"
#include <algorithm>
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
    if (vertex != nullptr) {
        auto lines = vertex->getLines();
        for (int i = lines.size() - 1; i >= 0; i--) {
            removeLine(lines[i]);
        }

        // Corrige os identificadores dos vértices para condizer com suas posições na lista
        for (int i = vertex->getId() + 1; i < vertices.size(); i++) {
            vertices[i]->setId(vertices[i]->getId() - 1);
        }

        vertices.removeOne(vertex);
        removeItem(vertex);
        delete vertex;
    }
}

void GraphicsScene::createLine(Vertex *item, bool isDirected, bool isWeighted)
{
    // Create a graphical edge, giving feedback to the user.
    Edge e(isDirected, isWeighted);
    e.setV1(item);
    currentLine = new RegularEdge(e); // Stores a copy
    addItem(currentLine);
}

void GraphicsScene::removeLine(EdgeInterface* edge) {

    if (edge != nullptr) {
        Edge model = edge->getModel();
        qDebug() << "Removing id1: " << model.getV1()->getId() << "; id2: " << model.getV2()->getId();

        model.getV1()->removeConnection(edge);
        model.getV2()->removeConnection(edge);

        removeItem(edge->getItem());

        EdgeInterface* reverse = findLine(model.getV2()->getId(), model.getV1()->getId());
        if (reverse != nullptr) {
            reverse->centralize();
        }
    }
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
        addItem(line->getItem());
        removeCurrentLine();
    }

    vertices[id1]->addConnection(line);

    if (id1 != id2) { // No need to add twice if it's a self loop
        vertices[id2]->addConnection(line);
    }

    line->centralize();

    EdgeInterface* reverse = findLine(id2, id1);
    if (reverse != nullptr) {
        reverse->centralize();
    }
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

    int nColors = *std::max_element(cores.begin(), cores.end()) + 1;
    int value = 360 / nColors;
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
        vertices[a.origem]->setPen(pen);
        vertices[a.origem]->paintEdge(a.destino);
        vertices[a.destino]->setPen(pen);
        repaintViews();
        sleep(500);
    }
}

void GraphicsScene::paintSequence(QVector<int> sequence) {
    for (int id : sequence) {
        vertices[id]->setPen(QPen(QBrush(QColor("#19a019")), 4));
        repaintViews();
        sleep(750);
    }
}

void GraphicsScene::displayFlow(QVector<Arco> residuals)
{
    for (Vertex* v : vertices) {
        for (EdgeInterface* edge : v->getLines()) {
            Edge e = edge->getModel();

            QVector<Arco>::iterator it = std::find_if(residuals.begin(), residuals.end(), [&](Arco a) {
                return a.origem == e.getV1()->getId() && a.destino == e.getV2()->getId();
            });

            if (it == residuals.end()) {
                e.setFlow(e.getWeight());
            } else {
                e.setFlow(e.getWeight() - it->peso);
            }

            edge->setModel(e);
        }
    }

    repaintViews();
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

void GraphicsScene::resetFlow()
{
    for (Vertex* v : vertices) {
        for (EdgeInterface* edge : v->getLines()) {
            Edge e = edge->getModel();
            e.setFlow(Edge::NoFlow);
            edge->setModel(e);
        }
    }

    repaintViews();
}

void GraphicsScene::prepareDijkstra(Vertex *item)
{
    sourceVertex = item;
    performingDijkstra = true;
}

void GraphicsScene::executeSecondClickAction(Vertex *vertex)
{
    if(isCreatingEdge()) {
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
        if (isCreatingEdge()) {
            removeCurrentLine();
        }

        resetControlVaraibles();
        emit resetCursor();
    }
}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (isCreatingEdge()) {
        Vertex* origin = currentLine->getModel().getV1();
        currentLine->setLine(origin->getCenter(), event->scenePos());
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
    if (isCreatingEdge()) {
        removeItem(currentLine);
        delete currentLine;
        currentLine = nullptr;
    }
}

bool GraphicsScene::isCreatingEdge()
{
    return currentLine != nullptr;
}

int GraphicsScene::getTypeOfItemAt(QPointF point)
{
    QGraphicsItem* item = itemAt(point, QTransform());
    if (item != nullptr) {
        return item->type();
    }
    return -1;
}
