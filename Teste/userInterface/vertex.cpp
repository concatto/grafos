#include "vertex.h"
#include <QBrush>
#include <QDebug>
#include <QGraphicsSceneMoveEvent>
#include "graphicsscene.h"
#include <QGraphicsView>
#include <QTextOption>
#include <cmath>

bool operator >(QPointF p1, QPointF p2){
    return (p1.x() > p2.x() && p1.y() > p2.y() && p2.x() > 30 && p2.y() > 30);
}

QRectF operator +(QRectF v1, qreal v2){
    v1.setHeight(v1.height() + v2 + 15);
    return v1;
}

Vertex::Vertex(float radius, QString name)
    : QGraphicsEllipseItem(0, 0, radius * 2, radius * 2), radius(radius)
{
    setBrush(Qt::red);
    id = indexCounter;
    indexCounter++;
    this->name = name;
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
    pressed = false;
}

int Vertex::indexCounter = 0;

void Vertex::handleMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton && pressed){
        QPointF delta = event->scenePos() - event->lastScenePos();
        moveBy(delta.x(), delta.y());
        alignEdges();
    }
}

void Vertex::alignEdges()
{
    for(EdgeInterface *nav: lines) {
        nav->centralize();
    }
}

void Vertex::setPressed(bool value)
{
    pressed = value;
}

float Vertex::getRadius() const
{
    return radius;
}

bool Vertex::getPressed() const
{
    return pressed;
}

void Vertex::setId(int value)
{
    id = value;
}

QPointF Vertex::getCenter() const
{
    return pos() + QPointF(radius, radius);
}

QString Vertex::getName()
{
    return name;
}

void Vertex::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsEllipseItem::paint(painter, option, widget);
    QRectF wideRect = rect().marginsAdded(QMarginsF(80, 0, 80, 0));

    painter->drawText(wideRect.translated(0, rect().height()), Qt::AlignHCenter, this->name);
}

bool Vertex::addConnection(EdgeInterface *line)
{
    lines.append(line);
    return true;
}


QVariant Vertex::itemChange(GraphicsItemChange change, const QVariant &value)
{
    return QGraphicsItem::itemChange(change, value);
}

int Vertex::type() const
{
    return Type;
}

void Vertex::removeConnection(EdgeInterface *line)
{
    lines.removeOne(line);
}

void Vertex::paintEdge(int target)
{
    for (EdgeInterface* edge : lines) {
        Edge model = edge->getModel();

        if (target == -1) {
            edge->setStyle(Qt::black, 4);
        } else if (target == model.getV2()->getId()
                   || (!model.isDirected() && target == model.getV1()->getId())) {
            edge->setStyle(Qt::blue, 4);
        }
    }
}

int Vertex::getId()
{
    return this->id;
}

bool Vertex::hasLine(int origin, int destination) const
{
    for (EdgeInterface* edge : lines) {
        Edge line = edge->getModel();
        if (line.getV1()->getId() == origin && line.getV2()->getId() == destination) {
            return true;
        }
    }

    return false;
}

const QVector<EdgeInterface*>& Vertex::getLines() const
{
    return lines;
}
