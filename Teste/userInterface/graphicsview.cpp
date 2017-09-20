#include "graphicsview.h"
#include <QContextMenuEvent>
#include <QCursor>
#include <QDebug>
#include <QInputDialog>
#include <QDir>
#include <QMessageBox>

GraphicsView::GraphicsView() : scene()
{
    this->setScene(&scene);
    this->menuList.addAction("Inserir vértice");
    this->menuList.addAction("Imprimir");
    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    //menuList.addAction("");
//    setFixedSize(800, 600);
}


void GraphicsView::contextMenuEvent(QContextMenuEvent *event)
{
    if(Vertex *item = (Vertex*)itemAt(event->pos())){
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
            }else{
                qDebug()<<"no";
            }

            emit removeVertex(item->getName());
            scene.removeItem(item);
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
