#include "graphicsview.h"
#include <QContextMenuEvent>
#include <QCursor>
#include <QDebug>
#include <QInputDialog>
#include <QDir>
#include <QCoreApplication>
#include <QMessageBox>

GraphicsView::GraphicsView() : scene()
{
    this->setScene(&scene);
    this->menuList.addAction("Inserir vértice");
    this->menuList.addAction("Imprimir");
    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    //menuList.addAction("");
    setFixedSize(770, 570);
    setFrameShape(QGraphicsView::NoFrame);
    QObject::connect(&scene, SIGNAL(addConnection(QString,QString,int)), this, SIGNAL(addConnection(QString,QString,int)));
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
                    qDebug()<<"yes";
                    emit removeVertex(item->getName());
                    scene.removeItem(item);
                }else{
                    qDebug()<<"no";
                }
            }else if(action->text() == QString("Inserir aresta")){
                Vertex *item = (Vertex*)itemAt(event->pos());
                scene.setLine(item);
            }
        }else if(2 == item->type()){
            qDebug()<<"fuckin gambiarra funcionou";
        }
    }else{
        QAction *action = NULL;
        action = menuList.exec(QCursor::pos());

        if(action == NULL)
            return;

        if(action->text() == QString("Inserir vértice")){
            bool ok;
            QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                                 tr("Nome do Vértice:"), QLineEdit::Normal,
                                                 "", &ok);
            scene.addVertex(text);
            emit addVertex(text);
        }
    }
}
