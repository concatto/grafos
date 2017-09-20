#include "graphicsview.h"
#include <QContextMenuEvent>
#include <QCursor>
#include <QDebug>
#include <QInputDialog>
#include <QDir>
#include <QGraphicsSceneContextMenuEvent>


GraphicsView::GraphicsView() : scene()
{
    this->setScene(&scene);
    this->menuList.addAction("Inserir vértice");
    this->menuList.addAction("Imprimir");
    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    setSceneRect(0, 0, 400, 600);
    //menuList.addAction("");
}


void GraphicsView::contextMenuEvent(QContextMenuEvent *event)
{
    if(Vertex *item = (Vertex*)itemAt(event->pos())){
        item->contextMenuEvent((QGraphicsSceneContextMenuEvent*) event);
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
