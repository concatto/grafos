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

bool Vertex::compareLines(Edge *l1, Edge *l2)
{
    return ((l1->getV1()->getId() == l2->getV1()->getId() && l1->getV2()->getId() == l2->getV2()->getId())
            || (l1->getV1()->getId() == l2->getV2()->getId() && l1->getV2()->getId() == l2->getV1()->getId()));

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
//    this->boundingRect().bottom();


    painter->drawText(rect().marginsAdded(QMarginsF(80, 0, 80, 0)) + rect().height(), Qt::AlignCenter, this->name);
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

void Vertex::removeConnections()
{
//    for(EdgeInterface *line : lines) {
//        Edge model = line->getModel();
//        if(model.getV1()->getId() == id){
//            model.getV2()->removeConnection(line);
//        }else {
//            model.getV1()->removeConnection(line);
//        }
//        //delete model; //Careful here
//    }
}

void Vertex::print()
{
//    for(Line *l: lines){
//        qDebug()<<l->line->getV2()->getName();
//    }
}

void Vertex::paintEdge(int vertice)
{
//    if(vertice == -1){ // Reset colors
//        for(Edge *line: lines){
//            line->setCustomPen(QPen(QBrush(Qt::black), 4));
////            line->line->update();
//        }
//        return;
//    }

//    for(Edge *line: lines){
//        if(line->getV1()->getId() == id){
//            if(line->getV2()->getId() == vertice){
//                line->setCustomPen(QPen(QBrush(Qt::blue), 4));
//            }
//        }else {
//            if(line->getV1()->getId() == vertice){
//                line->setCustomPen(QPen(QBrush(Qt::blue), 4));
//            }
//        }
//    }
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
