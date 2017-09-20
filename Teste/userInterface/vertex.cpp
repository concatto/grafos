#include "vertex.h"
#include <QBrush>
#include <QDebug>
#include <QGraphicsSceneMoveEvent>


Vertex::Vertex(float radius, QString name) : QGraphicsEllipseItem(0, 0, radius, radius)
{
    this->name = name;
    setBrush(QBrush(Qt::red));
    menuList = new QMenu();
    menuList->addAction("Remover vértice");
}

void Vertex::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    (void)event;
}

void Vertex::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //TODO melhorar
    if(event->buttons() & Qt::LeftButton){
        QPointF delta = event->scenePos() - event->lastScenePos();
        moveBy(delta.x(), delta.y());
    }
}

void Vertex::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    (void)event;
}


void Vertex::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
//    QAction *action = NULL;
//    action = menuList.exec(QCursor::pos());

//    if(action == NULL)
//        return;

//    if(action->text() == QString("Remover vértice")){
//        bool ok;
//        QString text = QInputDialog::getText(this, QObject::tr("QInputDialog::getText()"),
//                                             QObject::tr("Nome do Vértice:"), QLineEdit::Normal,
//                                             "", &ok);
//    }
}

QMenu* Vertex::getMenu()
{
    return menuList;
}

QString Vertex::getName()
{
    return name;
}
