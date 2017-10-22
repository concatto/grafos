#include "straightedge.h"

int StraightEdge::type() const
{
    return Type;
}

StraightEdge::StraightEdge(bool isDirected, bool isWeighted) : GraphicsLine(isDirected, isWeighted)
{
    setPen(QPen(QBrush(Qt::black), 4));
    setZValue(-1);
}

void StraightEdge::setCustomPen(QPen pen)
{
    setPen(pen);
}

void StraightEdge::tryCentralize()
{
    if (v1 != nullptr && v2 != nullptr) {
        setLine(QLineF(v1->getCenter(), v2->getCenter()));
    }
}

void StraightEdge::setEndpoints(QPointF a, QPointF b)
{
    setLine(QLineF(a, b));
}

QGraphicsItem* StraightEdge::item()
{
    return this;
}

void StraightEdge::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen = painter->pen();
    QBrush brush = painter->brush();

    if (weighted) {
        qreal distance = 13;
        QPointF p = (line().p2() + line().p1())/2;

        qreal angle1 = line().angle() + 90;
        angle1 = angle1 * M_PI / 180;
        QPointF pn(p.x() + distance * cos(angle1), p.y() - distance * sin(angle1));

        if (weight != 0) {
            painter->setFont(QFont("times", 12));
            QRect rect = painter->fontMetrics().boundingRect(QString::number(weight));
            rect.moveCenter(pn.toPoint());

            painter->drawText(rect, Qt::AlignCenter, QString::number(weight));
        }
    }

    if (directed) {
        bool hasReverse = getV2() != nullptr && getV1()->hasLine(getV2()->getId(), getV1()->getId());
        double radius = getV1()->getRadius();

        if (hasReverse) {
            // Implementar arcos curvados algum dia.
//            QRectF rect(line().p1(), QSizeF(line().dx(), line().dy()));

//            int startAngle = 30 * 16;
//            int spanAngle = 120 * 16;

//            painter->drawArc(rect.normalized(), startAngle, spanAngle);

            if(getV1()->getId() == getV2()->getId()){
                painter->setPen(QPen(Qt::black, 4));
                painter->drawEllipse(getV1()->getCenter() - QPointF(0, radius), 15, 30);
            }
            QGraphicsLineItem::paint(painter, option, widget);
        } else {
            QGraphicsLineItem::paint(painter, option, widget);
        }

        double theta = (line().angle() / 180.0) * M_PI;

        if (getV2() == nullptr) {
            radius = 0;
        }

        QPointF t2 = line().p2() - QPointF(radius * std::cos(theta), -radius * std::sin(theta));

        double distance = 14;
        double yspace = 6;
        QPointF ti = t2 - QPointF(distance * std::cos(theta), -distance * std::sin(theta));

        double theta1 = theta + (M_PI / 2);
        QPointF t1 = ti + QPointF(yspace * std::cos(theta1), -yspace * std::sin(theta1));
        QPointF t3 = ti + QPointF(yspace * std::cos(theta1 + M_PI), -yspace * std::sin(theta1 + M_PI));

        painter->setBrush(Qt::black);
        painter->drawConvexPolygon(QPolygonF({t1, t2, t3}));
    } else {
        QGraphicsLineItem::paint(painter, option, widget);
    }
}
