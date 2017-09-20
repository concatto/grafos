#include "vertexitem.h"
#include <QBrush>
#include <QDebug>
#include <QGraphicsSceneMoveEvent>

VertexItem::VertexItem(float radius) : QGraphicsEllipseItem(0, 0, radius, radius)
{
    setBrush(QBrush(Qt::red));
}

void VertexItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}

void VertexItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //TODO melhorar
    QPointF delta = event->scenePos() - event->lastScenePos();
    moveBy(delta.x(), delta.y());
}

void VertexItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

}
