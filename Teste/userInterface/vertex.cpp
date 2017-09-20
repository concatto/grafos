#include "vertex.h"
#include <QBrush>
#include <QDebug>
#include <QGraphicsSceneMoveEvent>

Vertex::Vertex(float radius) : QGraphicsEllipseItem(0, 0, radius, radius)
{
    setBrush(QBrush(Qt::red));
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
    qDebug()<<"papai chegou";
}
