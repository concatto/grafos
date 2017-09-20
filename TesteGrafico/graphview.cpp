#include "graphview.h"
#include <QContextMenuEvent>
#include <QCursor>
#include <QDebug>
#include <QInputDialog>
#include <QDir>

GraphView::GraphView() : scene()
{
    this->setScene(&scene);
    menuList.addAction("Inserir vértice");
    menuList.addAction("Imprimir");
    //menuList.addAction("");
}


void GraphView::contextMenuEvent(QContextMenuEvent *event)
{

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
    }
}
