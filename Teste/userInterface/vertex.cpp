#include "vertex.h"
#include <QBrush>
#include <QDebug>
#include <QGraphicsSceneMoveEvent>
#include "graphicsscene.h"
#include <QGraphicsView>
#include <QTextOption>

bool operator >(QPointF p1, QPointF p2){
    return (p1.x() > p2.x() && p1.y() > p2.y() && p2.x() > 30 && p2.y() > 30);
}

QRectF operator +(QRectF v1, qreal v2){
    v1.setHeight(v1.height() + v2 + 15);
    return v1;
}

Vertex::Vertex(float radius, QString name) : QGraphicsEllipseItem(0, 0, radius, radius)
{
    this->name = name;
    setBrush(QBrush(Qt::red));
    menuList = new QMenu();
    menuList->addAction("Remover vértice");
    menuList->addAction("Inserir aresta");
}

void Vertex::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    (void)event;
    emit drawEdge(this);
}

void Vertex::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

//    qDebug()<<scene()->views().first()->mapFromScene(mapToScene(QPointF(this->x(), this->y())));
    if(event->buttons() & Qt::LeftButton/* && sceneBoundingRect().y() > -115*/){
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


void Vertex::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsEllipseItem::paint(painter, option, widget);
    this->boundingRect().bottom();
    painter->drawText(this->rect() + this->rect().height(), Qt::AlignCenter, this->name);
}
