#include "regularedge.h"
#include <QVariant>
#include <QDebug>
#include <cmath>
#include <QtMath>

RegularEdge::RegularEdge(Edge edge)
{
    setModel(edge);
    setStyle(Qt::black, 2);
    setZValue(-1);

    QPointF center = edge.getV1()->getCenter();
    setLine(center, center);
}

void RegularEdge::setLine(const QPointF& start, const QPointF& end)
{
    QPainterPath path(start);

    Vertex* v2 = getModel().getV2();

    // If there is an edge coming back here
    if (v2 != nullptr && v2->hasLine(v2->getId(), getModel().getV1()->getId())) {
        QPointF middle = (start + end) * 0.5;
        float theta = qDegreesToRadians(QLineF(start, end).angle() + 90);
        float length = 20;
        middle.rx() += std::cos(theta) * length;
        middle.ry() -= std::sin(theta) * length;

        path.quadTo(middle, end);
    } else {
        path.lineTo(end);
    }

    setPath(path);
}

int RegularEdge::type() const
{
    return Type;
}

void RegularEdge::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Edge edge = getModel();
    QGraphicsPathItem::paint(painter, option, widget);

    if (edge.isWeighted()) {
        qreal distance = 13;
        QPointF p = path().pointAtPercent(0.5);

        qreal angle1 = qDegreesToRadians(path().angleAtPercent(0.5) + 90);
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
        double theta = qDegreesToRadians(path().angleAtPercent(0.95));

        if (edge.getV2() == nullptr) {
            radius = 0;
        }

        // Draws a triangle
        QPointF t2 = path().pointAtPercent(1) - QPointF(radius * std::cos(theta), -radius * std::sin(theta));

        double distance = 14;
        double yspace = 6;
        QPointF ti = t2 - QPointF(distance * std::cos(theta), -distance * std::sin(theta));

        double theta1 = theta + (M_PI / 2);
        QPointF t1 = ti + QPointF(yspace * std::cos(theta1), -yspace * std::sin(theta1));
        QPointF t3 = ti + QPointF(yspace * std::cos(theta1 + M_PI), -yspace * std::sin(theta1 + M_PI));

        painter->setBrush(pen().color());
        painter->drawConvexPolygon(QPolygonF({t1, t2, t3}));
    }
}

Edge RegularEdge::getModel()
{
    return model;
}

void RegularEdge::setModel(Edge model)
{
    this->model = model;
}

void RegularEdge::centralize()
{
    Vertex* v1 = model.getV1();
    Vertex* v2 = model.getV2();
    if (v1 != nullptr && v2 != nullptr) {
        setLine(v1->getCenter(), v2->getCenter());
    }
}

QGraphicsItem* RegularEdge::getItem()
{
    return this;
}

void RegularEdge::setStyle(Qt::GlobalColor color, int width)
{
    setPen(QPen(QBrush(color), width));
}
