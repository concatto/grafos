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

    isDirected ? lineMenuList.addAction("Remover Arco") : lineMenuList.addAction("Remover Aresta");

    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    //menuList.addAction("");
    setFixedSize(770, 570);
    setFrameShape(QGraphicsView::NoFrame);
    setMouseTracking(true); //Permite que MouseMoveEvents sejam detectados pela scene sem clique prévio
    QObject::connect(&scene, SIGNAL(addConnection(int, int,int)), this, SIGNAL(addConnection(int, int,int)));
    QObject::connect(&scene, SIGNAL(duplicatedEdge()), this, SLOT(duplicatedEdge()));
    QObject::connect(&scene, SIGNAL(duplicatedVertex()), this, SLOT(duplicatedVertex()));
    QObject::connect(&scene, SIGNAL(performDijkstra(int, int)), this, SIGNAL(performDijkstra(int, int)));
    QObject::connect(&scene, SIGNAL(resetCursor()), this, SLOT(resetCursor()));
}

void GraphicsView::paintVertices(QVector<int> cores)
{
//    scene.
    QBrush brush(Qt::black);
    scene.paintVertices(cores, &brush);
    scene.paintVertices(cores);
}

void GraphicsView::paintDijkstra(QStack<int> stack)
{
    scene.paintDijkstra(stack);
}


void GraphicsView::contextMenuEvent(QContextMenuEvent *event)
{
    if(QGraphicsItem *item = itemAt(event->pos())){
        if(1 == item->type()){
            Vertex *vertex = (Vertex*)item;
            QAction *action = NULL;
            action = vertexMenuList.exec(QCursor::pos());

            if(action == NULL)
                return;

            if(action == vertexMenuList.actions().at(1)){ // Remover vértice
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Remover vértice", "Você tem certeza que deseja remover este vértice?",
                                              QMessageBox::Yes|QMessageBox::No);
                if(reply == QMessageBox::Yes){
                    vertex->removeConnections();

                    emit removeVertex(vertex->getId());
                    scene.removeVertex(vertex);
                }
            }else if(action == vertexMenuList.actions().at(0)){ // Inserir arco ou aresta
                scene.createLine(vertex, isWeighted);
                setViewCursor(Qt::PointingHandCursor);
            }else if(action == vertexMenuList.actions().at(2)){ // Dijkstra
                scene.setDijkstra(vertex);
                setViewCursor(Qt::PointingHandCursor);
            }
        }else if(2 == item->type()){
            GraphicsLine *gline = (GraphicsLine*)item;

            QAction *action = NULL;
            action = lineMenuList.exec(QCursor::pos());

            if(action == NULL)
                return;

            if(action == lineMenuList.actions().at(0)){ //Remover aresta ou arco

                Vertex *vertex1 = gline->getV1();
                Vertex *vertex2 = gline->getV2();

                vertex1->removeConnection(gline);
                vertex2->removeConnection(gline);

                scene.removeItem(gline);
                emit removeConnection(vertex1->getId(), vertex2->getId());
                delete gline;
            }
        }
    }else{
        QAction *action = NULL;
        action = viewMenuList.exec(QCursor::pos());

        if(action == NULL)
            return;

        if(action == viewMenuList.actions().at(0)){ //Inserir vértice
            bool ok = false;
            QString text;
            while(text.isEmpty()){
                text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                                     tr("Nome do Vértice:"), QLineEdit::Normal,
                                                     "", &ok);
                if(!ok)
                    return;
            }
            if(scene.addVertex(text, mapToScene(event->pos()))){
                emit addVertex(text);
            }

        }else if(action == viewMenuList.actions().at(1)){ //Welsh and Powell
            emit performWelshPowell();
        }else if(action == viewMenuList.actions().at(2)){ // Dsatur
            emit performDsatur();
        }else if(action == viewMenuList.actions().at(3)){ // Resetar cores
            QBrush brush(Qt::red);
            scene.paintVertices(QVector <int>(), &brush);
        }else if(action == viewMenuList.actions().at(4)){ // Print -- only for debugging
            scene.print();
        }
    }
}

void GraphicsView::setViewCursor(QCursor cursor)
{
    viewport()->setCursor(cursor);
}

void GraphicsView::duplicatedEdge()
{
    setViewCursor(Qt::ArrowCursor);
    QMessageBox msgBox;
    msgBox.setWindowTitle("Aresta duplicada");
    msgBox.setText("Não é permitido inserir arestas duplicadas");
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}

void GraphicsView::duplicatedVertex()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Vértice duplicado");
    msgBox.setText("Não é permitido inserir vértices duplicados");
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}

void GraphicsView::resetCursor()
{
    setViewCursor(Qt::ArrowCursor);
}
