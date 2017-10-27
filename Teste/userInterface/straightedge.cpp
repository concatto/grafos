#include "straightedge.h"
#include <QVariant>
#include <QDebug>
#include <cmath>
#include <QtMath>

StraightEdge::StraightEdge(Edge edge)
{
    setModel(edge);
    setPen(QPen(QBrush(Qt::black), 4));
    setZValue(-1);

    QPointF center = edge.getV1()->getCenter();
    setLine(QLineF(center, center));
}

int StraightEdge::type() const
{
    return Type;
}

void StraightEdge::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Edge edge = getModel();
    QGraphicsLineItem::paint(painter, option, widget);

    if (edge.isWeighted()) {
        qreal distance = 13;
        QPointF p = (line().p2() + line().p1()) / 2;

        qreal angle1 = qDegreesToRadians(line().angle() + 90);
        QPointF pn(p.x() + distance * cos(angle1), p.y() - distance * sin(angle1));

        QString numStr = QString::number(edge.getWeight());
        if (edge.getWeight() != 0) {
            painter->setFont(QFont("times", 12));
            QRect rect = painter->fontMetrics().boundingRect(numStr);
            rect.moveCenter(pn.toPoint());

            painter->drawText(rect, Qt::AlignCenter, numStr);
        }
    }

    if (edge.isDirected()) {
        double radius = edge.getV1()->getRadius();

        /*
        bool hasReverse = edge.getV2() != nullptr && edge.getV1()->hasLine(edge.getV2()->getId(), edge.getV1()->getId());

        if (hasReverse) {
            // Implementar arcos curvados algum dia.
//            QRectF rect(line().p1(), QSizeF(line().dx(), line().dy()));

//            int startAngle = 30 * 16;
//            int spanAngle = 120 * 16;

//            painter->drawArc(rect.normalized(), startAngle, spanAngle);

            if(edge.getV1()->getId() == edge.getV2()->getId()){
                painter->setPen(QPen(Qt::black, 4));
                painter->drawEllipse(getV1()->getCenter() - QPointF(0, radius), 15, 30);
            }
            QGraphicsLineItem::paint(painter, option, widget);
        } else {
            QGraphicsLineItem::paint(painter, option, widget);
        }
        */

        double theta = qDegreesToRadians(line().angle());

        if (edge.getV2() == nullptr) {
            radius = 0;
        }

        // Draws a triangle
        QPointF t2 = line().p2() - QPointF(radius * std::cos(theta), -radius * std::sin(theta));

        double distance = 14;
        double yspace = 6;
        QPointF ti = t2 - QPointF(distance * std::cos(theta), -distance * std::sin(theta));

        double theta1 = theta + (M_PI / 2);
        QPointF t1 = ti + QPointF(yspace * std::cos(theta1), -yspace * std::sin(theta1));
        QPointF t3 = ti + QPointF(yspace * std::cos(theta1 + M_PI), -yspace * std::sin(theta1 + M_PI));

        painter->setBrush(Qt::black);
        painter->drawConvexPolygon(QPolygonF({t1, t2, t3}));
    }
}

Edge StraightEdge::getModel()
{
    return model;
}

void StraightEdge::setModel(Edge model)
{
    this->model = model;
}

void StraightEdge::centralize()
{
    Vertex* v1 = model.getV1();
    Vertex* v2 = model.getV2();
    if (v1 != nullptr && v2 != nullptr) {
        setLine(QLineF(v1->getCenter(), v2->getCenter()));
    }
}

QGraphicsItem* StraightEdge::getItem()
{
    return this;
}
