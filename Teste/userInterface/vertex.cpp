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
    : QGraphicsEllipseItem(0, 0, radius, radius)
{
    setBrush(Qt::red);
    id = indexCounter;
    indexCounter++;
    this->name = name;
    menuList = new QMenu();
    menuList->addAction("Remover vértice");
    menuList->addAction("Inserir aresta");
    menuList->addAction("Dijkstra a partir deste vértice");
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
//    setFlag(QGraphicsItem::ItemIsMovable);
}

void Vertex::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
}

int Vertex::indexCounter = 0;

void Vertex::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton/* && sceneBoundingRect().y() > -115*/){
        QPointF delta = event->scenePos() - event->lastScenePos();
        moveBy(delta.x(), delta.y());
        moveLineToCenter(pos());
    }
}

void Vertex::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->type() & Qt::LeftButton){
        emit mousePressed(this);
    }
}

bool Vertex::compareLines(GraphicsLine *l1, GraphicsLine *l2)
{
    return ((l1->getV1()->getId() == l2->getV1()->getId() && l1->getV2()->getId() == l2->getV2()->getId())
            || (l1->getV1()->getId() == l2->getV2()->getId() && l1->getV2()->getId() == l2->getV1()->getId()));

//    return ((l1->getV1() == l2->getV1() && l1->getV2() == l2->getV2())
//            || l1->getV1() == l2->getV2() && l1->getV2() == l2->getV1());

}

void Vertex::moveLineToCenter(QPointF newPos)
{

//    QPointF p1 = getV1()->rect().center();
//    QPointF p2 = getV2()->rect().center();

    int xOffset = rect().x() + rect().width()/2;
    int yOffset = rect().y() + rect().height()/2;

    QPointF newCenterPos = QPointF(newPos.x() + xOffset, newPos.y() + yOffset);

    for(Line *nav: lines){

        // Move the required point of the line to the center of the elipse
        QPointF p1 = nav->isP1 ? newCenterPos : nav->line->line().p1();
        QPointF p2 = nav->isP1 ? nav->line->line().p2() : newCenterPos;

        QPointF delta = p2 - p1;

        qreal angle1 = atan2(delta.y(), delta.x());
        qreal radius = rect().width()/2;

        qreal xOffset = radius * cos(angle1);
        qreal yOffset = radius * sin(angle1);

        // TODO Fix when nav->isP1 is true
        if(nav->isP1)
            nav->line->setLine(QLineF(p1, p2));
        else
            nav->line->setLine(QLineF(p1, p2 - QPointF(xOffset, yOffset)));
    }


}

void Vertex::setId(int value)
{
    id = value;
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
//    this->boundingRect().bottom();
    painter->drawText(this->rect() + this->rect().height(), Qt::AlignCenter, this->name);
}

bool Vertex::addConnection(GraphicsLine *line, bool p1)
{
    Line *nline = new Line(line, p1);

    if(line->getV2() != NULL){
        for(Line *l: lines){
            if(compareLines(l->line, line)){
                line->getV1()->removeConnection(line);
                line->getV2()->removeConnection(line);
                delete nline;
                return false;
            }
        }
    }

    lines.append(nline);


    if(p1){
        int xOffset = rect().x() + rect().width()/2;
        int yOffset = rect().y() + rect().height()/2;

        QPointF newCenterPos = QPointF(this->scenePos().x() + xOffset, this->scenePos().y() + yOffset);

        lines.back()->line->setLine(QLineF(newCenterPos, QPointF(0, 0)));

    }else {
        QPointF p1 = line->line().p1();
        QPointF p2 = rect().center();

        QPointF delta = p2 - p1;

        qreal angle1 = atan2(delta.y(), delta.x());
        qreal radius = rect().width()/2;

        qreal dxOffset = radius * cos(angle1);
        qreal dyOffset = radius * sin(angle1);



        int xOffset = rect().x() + rect().width()/2;
        int yOffset = rect().y() + rect().height()/2;

        QPointF newCenterPos = QPointF(this->scenePos().x() + xOffset, this->scenePos().y() + yOffset);

        lines.back()->line->setLine(QLineF(line->line().p1(), newCenterPos - QPointF(dxOffset, dyOffset)));
    }

    return true;

}


QVariant Vertex::itemChange(GraphicsItemChange change, const QVariant &value)
{
//    if(lines.size() > 0){
//        if (change == ItemPositionChange && scene()) {
//            QPointF newPos = value.toPointF();

//            moveLineToCenter(newPos);
//        }
//    }

    return QGraphicsItem::itemChange(change, value);
}



int Vertex::type() const
{
    return 1;
}

void Vertex::removeConnection(GraphicsLine *line)
{
    for(Line *l : lines){
        if(l->line == line){
            lines.removeOne(l);
        }
    }
}

void Vertex::removeConnections()
{
    for(Line *l : lines){
        if(l->isP1){
            l->line->getV2()->removeConnection(l->line);
        }else {
            l->line->getV1()->removeConnection(l->line);
        }
        delete l->line;
        delete l;
    }
}

void Vertex::print()
{
    for(Line *l: lines){
        qDebug()<<l->line->getV2()->getName();
    }
}

void Vertex::paintEdge(int vertice)
{
    if(vertice == -1){ // Reset colors
        for(Line *line: lines){
            line->line->setPen(QPen(QBrush(Qt::black), 4));
//            line->line->update();
        }
        return;
    }

    for(Line *line: lines){
        if(line->isP1){
            if(line->line->getV2()->getId() == vertice){
                line->line->setPen(QPen(QBrush(Qt::green), 4));
            }
        }else {
            if(line->line->getV1()->getId() == vertice){
                line->line->setPen(QPen(QBrush(Qt::green), 4));
            }
        }
    }
}

int Vertex::getId()
{
    return this->id;
}
