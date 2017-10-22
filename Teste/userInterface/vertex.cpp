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
        moveLineToCenter();
    }
}

bool Vertex::compareLines(GraphicsLine *l1, GraphicsLine *l2)
{
    return ((l1->getV1()->getId() == l2->getV1()->getId() && l1->getV2()->getId() == l2->getV2()->getId())
            || (l1->getV1()->getId() == l2->getV2()->getId() && l1->getV2()->getId() == l2->getV1()->getId()));

}

void Vertex::moveLineToCenter()
{
    for(GraphicsLine *nav: lines){
        nav->tryCentralize();
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

bool Vertex::addConnection(GraphicsLine *line)
{
//    if(line->getV2() != NULL){
//        for(GraphicsLine *l: lines){
//            if(compareLines(l, line)){
//                line->getV1()->removeConnection(line);
//                line->getV2()->removeConnection(line);
////                delete nline;
//                return false;
//            }
//        }
//    }

    lines.append(line);

    line->tryCentralize();

//    if(p1){
//        int xOffset = rect().x() + rect().width()/2;
//        int yOffset = rect().y() + rect().height()/2;

//        QPointF newCenterPos = QPointF(this->scenePos().x() + xOffset, this->scenePos().y() + yOffset);

//        lines.back()->line->setLine(QLineF(newCenterPos, QPointF(0, 0)));

//    }else {
//        QPointF p1 = line->line().p1();
//        QPointF p2 = rect().center();

//        QPointF delta = p2 - p1;

//        qreal angle1 = atan2(delta.y(), delta.x());
//        qreal radius = rect().width()/2;

//        qreal dxOffset = radius * cos(angle1);
//        qreal dyOffset = radius * sin(angle1);



//        int xOffset = rect().x() + rect().width()/2;
//        int yOffset = rect().y() + rect().height()/2;

//        QPointF newCenterPos = QPointF(this->scenePos().x() + xOffset, this->scenePos().y() + yOffset);

//        lines.back()->line->setLine(QLineF(line->line().p1(), newCenterPos - QPointF(dxOffset, dyOffset)));
//    }

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

void Vertex::removeConnection(GraphicsLine *line)
{

    lines.removeOne(line);

//    for(GraphicsLine *l : lines){
//        if(l == line){
//            lines.removeOne(l);
//        }
//    }
}

void Vertex::removeConnections()
{
    for(GraphicsLine *l : lines){
        if(l->getV1()->getId() == id){
            l->getV2()->removeConnection(l);
        }else {
            l->getV1()->removeConnection(l);
        }
        delete l;
    }
}

void Vertex::print()
{
//    for(Line *l: lines){
//        qDebug()<<l->line->getV2()->getName();
//    }
}

void Vertex::paintEdge(int vertice)
{
    if(vertice == -1){ // Reset colors
        for(GraphicsLine *line: lines){
            line->setCustomPen(QPen(QBrush(Qt::black), 4));
//            line->line->update();
        }
        return;
    }

    for(GraphicsLine *line: lines){
        if(line->getV1()->getId() == id){
            if(line->getV2()->getId() == vertice){
                line->setCustomPen(QPen(QBrush(Qt::blue), 4));
            }
        }else {
            if(line->getV1()->getId() == vertice){
                line->setCustomPen(QPen(QBrush(Qt::blue), 4));
            }
        }
    }
}

int Vertex::getId()
{
    return this->id;
}

bool Vertex::hasLine(int origin, int destination) const
{
    for (GraphicsLine* line : lines) {
        if (line->getV1()->getId() == origin && line->getV2()->getId() == destination) {
            return true;
        }
    }

    return false;
}
