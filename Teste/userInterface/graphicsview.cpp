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
    this->viewMenuList.addAction("Resetar cores");
    this->viewMenuList.addAction("Imprimir");


    isDirected ? vertexMenuList.addAction("Inserir Arco") : vertexMenuList.addAction("Inserir aresta");
    vertexMenuList.addAction("Remover vértice");
    vertexMenuList.addAction("Dijkstra a partir deste vértice");
    vertexMenuList.addAction("Busca em profundidade a partir deste vértice");
    vertexMenuList.addAction("Busca em largura a partir deste vértice");

    isDirected ? lineMenuList.addAction("Remover Arco") : lineMenuList.addAction("Remover Aresta");

    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    setFixedSize(770, 570);
    setFrameShape(QGraphicsView::NoFrame);
    setMouseTracking(true); //Permite que MouseMoveEvents sejam detectados pela scene sem clique prévio
    QObject::connect(&scene, SIGNAL(addConnection(int, int)), this, SLOT(askConnectionWeight(int, int)));
    QObject::connect(&scene, SIGNAL(performDijkstra(int, int)), this, SIGNAL(performDijkstra(int, int)));
    QObject::connect(&scene, SIGNAL(resetCursor()), this, SLOT(resetCursor()));
}

void GraphicsView::paintVertices(QVector<int> cores)
{
    QBrush brush(Qt::black);
    scene.paintVertices(cores, &brush);
    scene.paintVertices(cores);
}

void GraphicsView::paintDijkstra(QStack<int> stack)
{
    scene.paintDijkstra(stack);
}

void GraphicsView::createVertex(QString name)
{
    scene.addVertex(name, consumeMousePosition());
}

void GraphicsView::createConnection(int id1, int id2, int weight)
{
    scene.finishConnectionCreation(id1, id2, weight);
}

QPointF GraphicsView::consumeMousePosition()
{
    QPointF point(storedMousePosition);
    storedMousePosition = QPointF(0, 0);
    return point;
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

        if(action == 0) { // Inserir arco ou aresta
           scene.createLine(vertex, isWeighted);
           setViewCursor(Qt::PointingHandCursor);
        } else if(action == 1) { // Remover vértice
            handleVertexRemoval(vertex);
        }else if(action == 2){ // Dijkstra
            scene.prepareDijkstra(vertex);
            setViewCursor(Qt::PointingHandCursor);
        } else if(action == 3) {

        }
    }else if(type == GraphicsLine::Type){
        GraphicsLine *gline = scene.findItem<GraphicsLine>(pos);
        action = showMenu(lineMenuList);

        if(action == 0){ //Remover aresta ou arco
            handleConnectionRemoval(gline);
        }
    } else {
        action = showMenu(viewMenuList);

        if(action == 0){ //Inserir vértice
            handleVertexCreation();
        }else if(action == 1){ //Welsh and Powell
            emit performWelshPowell();
        }else if(action == 2){ // Dsatur
            emit performDsatur();
        }else if(action == 3){ // Resetar cores
            QBrush brush(Qt::red);
            scene.paintVertices(QVector <int>(), &brush);
        }else if(action == 4){ // Print -- only for debugging
            scene.print();
        }
    }
}

bool GraphicsView::isGraphDirected() const
{
    return isDirected;
}

bool GraphicsView::isGraphWeighted() const
{
    return isWeighted;
}

void GraphicsView::handleConnectionRemoval(GraphicsLine* line)
{
    Vertex *vertex1 = line->getV1();
    Vertex *vertex2 = line->getV2();

    vertex1->removeConnection(line);
    vertex2->removeConnection(line);

    scene.removeItem(line);
    emit removeConnection(vertex1->getId(), vertex2->getId());
    //delete line; // TODO corrigir, está causando bug
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
        vertex->removeConnections();
        scene.removeVertex(vertex);
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
