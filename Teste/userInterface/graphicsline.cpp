#include "graphicsline.h"
#include <QPainter>
#include <QPen>
#include <QDebug>
#include <math.h>
#define M_PI 3.14159265358979323846

GraphicsLine::GraphicsLine() : QGraphicsLineItem()
{
    this->v1 = NULL;
    this->v2 = NULL;
    menuList = new QMenu();
    menuList->addAction("Remover conexão");
    setPen(QPen(QBrush(Qt::black), 4));
}

int GraphicsLine::type() const
{
    return 2;
}

QMenu* GraphicsLine::getMenu()
{
    return menuList;
}

void GraphicsLine::setV1(Vertex *v1)
{
    this->v1 = v1;
}

void GraphicsLine::setV2(Vertex *v2)
{
    this->v2 = v2;
}

Vertex *GraphicsLine::getV1()
{
    return v1;
}

Vertex *GraphicsLine::getV2()
{
    return v2;
}

int GraphicsLine::getWeight()
{
    return weight;
}

void GraphicsLine::setWeight(int weight)
{
    this->weight = weight;
}


void GraphicsLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsLineItem::paint(painter, option, widget);

//    painter->drawText(QPointF(this->line().p2().x() - this->line().p1().x(), ), );

//    qreal arrowSize = 20;

//    double angle = ::acos(line().dx() / line().length());
//    if (line().dy() >= 0)
//        angle = (M_PI * 2) - angle;

//    QPointF arrowP1 = line().p2() - QPointF(sin(angle + M_PI / 3) * arrowSize,
//                                    cos(angle + M_PI / 3) * arrowSize);
//    QPointF arrowP2 = line().p2() - QPointF(sin(angle + M_PI - M_PI / 3) * arrowSize,
//                                    cos(angle + M_PI - M_PI / 3) * arrowSize);

//    painter->drawLine(QLineF(arrowP1.x(), arrowP1.y(), line().x2(), line().y2()));
//    painter->drawLine(QLineF(arrowP2.x(), arrowP2.y(), line().x2(), line().y2()));

}
