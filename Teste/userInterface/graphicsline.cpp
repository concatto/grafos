#include "graphicsline.h"
#include <QPainter>
#include <QPen>
#include <QDebug>
#include <math.h>
#define M_PI 3.14159265358979323846

GraphicsLine::GraphicsLine(bool weighted) : QGraphicsLineItem(), weighted(weighted)
{
    this->v1 = NULL;
    this->v2 = NULL;
    setPen(QPen(QBrush(Qt::black), 4));
    setZValue(-1);
}

int GraphicsLine::type() const
{
    return 2;
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

    if (weighted) {
        qreal distance = 13;
        QPointF p = (line().p2() + line().p1())/2;

        qreal angle1 = line().angle() + 90;
        angle1 = angle1 * M_PI / 180;
        QPointF pn(p.x() + distance * cos(angle1), p.y() - distance * sin(angle1));

        if (weight != 0) {
            painter->setFont(QFont("times", 12));
            painter->drawText(pn, QString::number(weight));
        }
    }


//    painter->drawText(line().length()/2, );

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

bool GraphicsLine::isWeighted() const
{
    return weighted;
}
