#include "selfloop.h"
#include <QtMath>
#include <cmath>

SelfLoop::SelfLoop(Edge edge)
{
    setModel(edge);
    setStyle(Qt::black, 4);
    setZValue(-1);
}

int SelfLoop::type() const
{
    return Type;
}

void SelfLoop::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Edge edge = getModel();
    QGraphicsEllipseItem::paint(painter, option, widget);

    if (edge.isWeighted()) {
        QPointF pn = rect().translated(-3, -2).center();

        QString numStr = edge.format();
        if (edge.getWeight() != 0) {
            QFont font = painter->font();
            font.setPixelSize(11);
            painter->setFont(font);
            QRect rect = painter->fontMetrics().boundingRect(numStr);
            rect.moveCenter(pn.toPoint());

            painter->drawText(rect, Qt::AlignCenter, numStr);
        }
    }

    if (edge.isDirected()) {
        double radius = edge.getV1()->getRadius();
        double theta = M_PI * 1.5;

        if (edge.getV2() == nullptr) {
            radius = 0;
        }

        // Draws a triangle
        QPointF t2 = model.getV1()->getCenter() - QPointF(radius * std::cos(theta), -radius * std::sin(theta));

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

Edge SelfLoop::getModel()
{
    return model;
}

void SelfLoop::setModel(Edge model)
{
    this->model = model;
}

void SelfLoop::centralize()
{
    Vertex* v = model.getV1();
    float radius = v->getRadius();
    QPointF topLeft(v->getCenter() - QPointF(radius, radius));
    QSizeF size = QSizeF(radius, radius) * 1.7;

    QRectF rect(QPointF(0, 0), size);
    rect.moveCenter(topLeft + QPointF(4, -9));

    setRect(rect);
}

QGraphicsItem* SelfLoop::getItem()
{
    return this;
}

void SelfLoop::setStyle(Qt::GlobalColor color, int width)
{
    setPen(QPen(QBrush(color), width));
}
