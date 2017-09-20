#include "vertex.h"
#include <QBrush>
#include <QDebug>
#include <QGraphicsSceneMoveEvent>
#include "graphicsscene.h"

bool operator >(QPointF p1, QPointF p2){
    return (p1.x() > p2.x() && p1.y() > p2.y() && p2.x() > 30 && p2.y() > 30);
}

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
//    qDebug()<<"Scene Rect Y: "<<scene()->sceneRect().height();
//    qDebug()<<"Event Scene Y: "<<event->scenePos().y();
//    qDebug()<<"This Y: "<<this->scenePos().y();
    //TODO melhorar
    if(event->buttons() & Qt::LeftButton)
/*        && ((QPointF(scene()->sceneRect().width(), scene()->sceneRect().height())
            - QPointF(this->rect().width(), this->rect().height())) >
            event->scenePos()))*/{

        QPointF delta = event->scenePos() - event->lastScenePos();
        moveBy(delta.x(), delta.y());
    }
}

void Vertex::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    (void)event;
}


QMenu* Vertex::getMenu()
{
    return menuList;
}

QString Vertex::getName()
{
    return name;
}
