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
            Vertex *item = (Vertex*)itemAt(event->pos());
            QMenu *tmp;
            tmp = item->getMenu();
            QAction *action = NULL;
            action = tmp->exec(QCursor::pos());

            if(action == NULL)
                return;

            if(action->text() == QString("Remover vértice")){
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Remover vértice", "Você tem certeza que deseja remover este vértice?",
                                              QMessageBox::Yes|QMessageBox::No);
                if(reply == QMessageBox::Yes){
                    item->removeConnections();

                    emit removeVertex(item->getId());
                    scene.removeVertex(item);
                }else{
                }
            }else if(action->text() == QString("Inserir aresta")){
//                Vertex *item = (Vertex*)itemAt(event->pos());
                scene.setLine(item);
                setViewCursor(Qt::PointingHandCursor);
            }else if(action->text() == QString("Dijkstra a partir deste vértice")){
//                Vertex *item = (Vertex*)itemAt(event->pos());
                scene.setDijkstra(item);
                setViewCursor(Qt::PointingHandCursor);
//                emit performDijkstra(item->getName());
            }
        }else if(2 == item->type()){
            GraphicsLine *item = (GraphicsLine *)itemAt(event->pos());
            QMenu *tmp;
            tmp = item->getMenu();
            QAction *action = NULL;
            action = tmp->exec(QCursor::pos());

            if(action == NULL)
                return;

            if(action->text() == QString("Remover conexão")){

                Vertex *vertex1 = item->getV1();
                Vertex *vertex2 = item->getV2();

                vertex1->removeConnection(item);
                vertex2->removeConnection(item);

                scene.removeItem(item);
                emit removeConnection(vertex1->getId(), vertex2->getId());
                delete item;
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

GraphicsView::setViewCursor(QCursor cursor)
{
    viewport()->setCursor(cursor);
}

void GraphicsView::duplicatedEdge()
{
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
