#include "graphicsview.h"
#include <QContextMenuEvent>
#include <QCursor>
#include <QDebug>
#include <QInputDialog>
#include <QDir>
#include <QCoreApplication>
#include <QMessageBox>
#include <QStack>

GraphicsView::GraphicsView(bool isWeighted, bool isDirected) :
    scene(), isWeighted(isWeighted), isDirected(isDirected)
{
    this->setScene(&scene);
    this->viewMenuList.addAction("Inserir vértice");
    this->viewMenuList.addAction("Welsh and Powell");
    this->viewMenuList.addAction("Dsatur");
    this->viewMenuList.addAction("Imprimir");
    this->viewMenuList.addAction("Resetar cores");

    vertexMenuList.addAction(isDirected ? "Inserir Arco" : "Inserir aresta");
    vertexMenuList.addAction("Remover vértice");
    vertexMenuList.addAction("Dijkstra a partir deste vértice");
    vertexMenuList.addAction("Busca em profundidade a partir deste vértice");
    vertexMenuList.addAction("Busca em largura a partir deste vértice");

    lineMenuList.addAction(isDirected ? "Remover Arco" : "Remover Aresta");

    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    setRenderHint(QPainter::Antialiasing, true);
    setFixedSize(770, 570);
    setFrameShape(QGraphicsView::NoFrame);
    setMouseTracking(true); //Permite que MouseMoveEvents sejam detectados pela scene sem clique prévio

    // A maioria destes sinais são emitidos pela cena quando o mouse é clicado pela segunda vez
    QObject::connect(&scene, SIGNAL(addConnection(int, int)), this, SLOT(askConnectionWeight(int, int)));
    QObject::connect(&scene, SIGNAL(performDijkstra(int, int)), this, SIGNAL(performDijkstra(int, int)));
    QObject::connect(&scene, SIGNAL(resetCursor()), this, SLOT(resetCursor()));
}

void GraphicsView::paintVertices(QVector<int> colors)
{
    QBrush brush(Qt::black);
    scene.paintVertices(colors, &brush);
    scene.paintVertices(colors);
}

void GraphicsView::paintPath(QVector<Arco> path)
{
    scene.paintPath(path);
}

void GraphicsView::paintSpanningTree(QVector<Arco> edges)
{
    // TODO fazer com que a scene pinte a árvore geradora
}

void GraphicsView::createVertex(QString name)
{
    scene.addVertex(name, storedMousePosition);
}

void GraphicsView::createConnection(int id1, int id2, int weight)
{
    scene.finishConnectionCreation(id1, id2, weight);
}

int GraphicsView::showMenu(QMenu &menu)
{
    QAction *action = NULL;
    action = menu.exec(QCursor::pos());

    if(action == NULL)
        return -1;

    return menu.actions().indexOf(action);
}

void GraphicsView::contextMenuEvent(QContextMenuEvent *event)
{
    QPointF pos = mapToScene(event->pos());

    storeMousePosition(pos);
    int type = scene.getTypeOfItemAt(pos);
    int action = -1;

    if (type == Vertex::Type){
        Vertex *vertex = scene.findItem<Vertex>(pos);
        action = showMenu(vertexMenuList);

        if (action == 0 || action >= 2) {
            // Estas ações demandam um segundo clique
            setViewCursor(Qt::PointingHandCursor);
        }

        if(action == 0) { // Inserir arco ou aresta
            scene.createLine(vertex, isDirected, isWeighted);
        }else if(action == 1) { // Remover vértice
            handleVertexRemoval(vertex);
        }else if(action == 2) { // Dijkstra
            scene.prepareDijkstra(vertex);
        } else if(action == 3) { // DFS

        } else if(action == 4) { // BFS

        }
    }else if(type == 0) {
//        Edge *gline = scene.findItem<Edge>(pos);
//        action = showMenu(lineMenuList);

//        if(action == 0){ //Remover aresta ou arco
//            emit removeConnection(gline->getV1()->getId(), gline->getV2()->getId());
//        }
    } else {
        action = showMenu(viewMenuList);

        if(action == 0){ //Inserir vértice
            handleVertexCreation();
        }else if(action == 1){ //Welsh and Powell
            emit performWelshPowell();
        }else if(action == 2){ // Dsatur
            emit performDsatur();
        }else if(action == 3){ // Print -- only for debugging
            emit printGraph();
        }else if(action == 4){ // Resetar cores
            QBrush brush(Qt::red);
            scene.paintVertices(QVector <int>(), &brush);
        }
    }
}

void GraphicsView::destroyConnection(int id1, int id2)
{
//    Edge* line = scene.findLine(id1, id2);

//    if (line != nullptr) {
//        Vertex *vertex1 = line->getV1();
//        Vertex *vertex2 = line->getV2();

//        vertex1->removeConnection(line);
//        vertex2->removeConnection(line);

////        scene.removeItem(line->item());
//    }
}

void GraphicsView::cancelConnection()
{
    scene.removeCurrentLine();
}

void GraphicsView::destroyVertex(int id)
{
    Vertex* vertex = scene.getVertex(id);

    if (vertex != nullptr) {
        vertex->removeConnections();
        scene.removeVertex(vertex);
    }
}

void GraphicsView::handleVertexCreation()
{
    bool ok = false;
    QString text;
    while (text.isEmpty()) {
        text = QInputDialog::getText(this, tr("Inserção de vértice"),
                                             tr("Insira o nome:"), QLineEdit::Normal,
                                             "", &ok);
        if (!ok)
            return;
    }

    emit addVertex(text);
}

void GraphicsView::handleVertexRemoval(Vertex* vertex)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Remover vértice", "Você tem certeza que deseja remover este vértice?",
                                  QMessageBox::Yes|QMessageBox::No);

    if(reply == QMessageBox::Yes){
        emit removeVertex(vertex->getId());
    }
}

void GraphicsView::setViewCursor(QCursor cursor)
{
    viewport()->setCursor(cursor);
}

void GraphicsView::storeMousePosition(QPointF position)
{
    storedMousePosition = position;
}

void GraphicsView::resetCursor()
{
    setViewCursor(Qt::ArrowCursor);
}

void GraphicsView::askConnectionWeight(int id1, int id2)
{
    int weight = 1;
    if (isWeighted) {
        bool ok = false;
        weight = QInputDialog::getInt(this, tr("Peso da aresta"),
                                            tr("Peso da aresta:"), 1, 0, 999, 1, &ok);
        if(!ok)
            return;
    }

    emit addConnection(id1, id2, weight);
}
