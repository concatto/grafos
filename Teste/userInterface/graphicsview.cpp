#include "graphicsview.h"
#include <QContextMenuEvent>
#include <QCursor>
#include <QDebug>
#include <QInputDialog>
#include <QDir>
#include <QCoreApplication>
#include <QMessageBox>
#include <QStack>

GraphicsView::GraphicsView() : scene()
{
    this->setScene(&scene);
    this->menuList.addAction("Inserir vértice");
    this->menuList.addAction("Welsh and Powell");
    this->menuList.addAction("Dsatur");
    this->menuList.addAction("Resetar cores");
    this->menuList.addAction("Imprimir");
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
//            Vertex *item = (Vertex*)itemAt(event->pos());
            Vertex *vertex = (Vertex*)item;
            QMenu *tmp;
            tmp = vertex->getMenu();
            QAction *action = NULL;
            action = tmp->exec(QCursor::pos());

            if(action == NULL)
                return;

            if(action->text() == QString("Remover vértice")){
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Remover vértice", "Você tem certeza que deseja remover este vértice?",
                                              QMessageBox::Yes|QMessageBox::No);
                if(reply == QMessageBox::Yes){
                    vertex->removeConnections();

                    emit removeVertex(vertex->getId());
                    scene.removeVertex(vertex);
                }else{
                }
            }else if(action->text() == QString("Inserir aresta")){
//                Vertex *item = (Vertex*)itemAt(event->pos());
                scene.setLine(vertex);
                setViewCursor(Qt::PointingHandCursor);
            }else if(action->text() == QString("Dijkstra a partir deste vértice")){
//                Vertex *item = (Vertex*)itemAt(event->pos());
                scene.setDijkstra(vertex);
                setViewCursor(Qt::PointingHandCursor);
//                emit performDijkstra(item->getName());
            }
        }else if(2 == item->type()){
//            GraphicsLine *item = (GraphicsLine *)itemAt(event->pos());
            GraphicsLine *gline = (GraphicsLine*)item;
            QMenu *tmp;
            tmp = gline->getMenu();
            QAction *action = NULL;
            action = tmp->exec(QCursor::pos());

            if(action == NULL)
                return;

            if(action->text() == QString("Remover conexão")){

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
        action = menuList.exec(QCursor::pos());

        if(action == NULL)
            return;

        if(action->text() == QString("Inserir vértice")){
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

        }else if(action->text() == QString("Welsh and Powell")){
            emit performWelshPowell();
        }else if(action->text() == QString("Dsatur")){
            emit performDsatur();
        }else if(action->text() == QString("Resetar cores")){
            QBrush brush(Qt::red);
            scene.paintVertices(QVector <int>(), &brush);
        }else if(action->text() == QString("Imprimir")){
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
