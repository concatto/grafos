#include "vertex.h"
#include <QBrush>
#include <QDebug>
#include <QGraphicsSceneMoveEvent>
#include "graphicsscene.h"
#include <QGraphicsView>
#include <QTextOption>

bool operator >(QPointF p1, QPointF p2){
    return (p1.x() > p2.x() && p1.y() > p2.y() && p2.x() > 30 && p2.y() > 30);
}

QRectF operator +(QRectF v1, qreal v2){
    v1.setHeight(v1.height() + v2 + 15);
    return v1;
}

Vertex::Vertex(float radius, QString name) : QGraphicsEllipseItem(0, 0, radius, radius)
{
    this->name = name;
    this->line = NULL;
    setBrush(QBrush(Qt::red));
    menuList = new QMenu();
    menuList->addAction("Remover vértice");
    menuList->addAction("Inserir aresta");
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
//    setFlag(QGraphicsItem::ItemIsMovable);
}

void Vertex::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    (void)event;
    emit drawEdge(this);
}

void Vertex::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    qDebug()<<scene()->views().first()->mapFromScene(mapToScene(QPointF(this->x(), this->y())));
    if(event->buttons() & Qt::LeftButton/* && sceneBoundingRect().y() > -115*/){
        QPointF delta = event->scenePos() - event->lastScenePos();
        moveBy(delta.x(), delta.y());
    }
}

void Vertex::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    (void)event;
}

void Vertex::moveLineToCenter(QPointF newPos)
{
    // Converts the elipse position (top-left)
    // to its center position
    int xOffset = rect().x() + rect().width()/2;
    int yOffset = rect().y() + rect().height()/2;


    QPointF newCenterPos = QPointF(newPos.x() + xOffset, newPos.y() + yOffset);

    // Move the required point of the line to the center of the elipse
    QPointF p1 = isP1 ? newCenterPos : line->line().p1();
    QPointF p2 = isP1 ? line->line().p2() : newCenterPos;

    line->setLine(QLineF(p1, p2));
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
    this->boundingRect().bottom();
    painter->drawText(this->rect() + this->rect().height(), Qt::AlignCenter, this->name);
    //    painter->drawL
}

void Vertex::addConnection(GraphicsLine *line, bool p1)
{

    this->line = line;
    this->isP1 = p1;

    if(p1){
        int xOffset = rect().x() + rect().width()/2;
        int yOffset = rect().y() + rect().height()/2;

        QPointF newCenterPos = QPointF(this->scenePos().x() + xOffset, this->scenePos().y() + yOffset);

        line->setLine(QLineF(newCenterPos, QPointF(0, 0)));

    }else {
        int xOffset = rect().x() + rect().width()/2;
        int yOffset = rect().y() + rect().height()/2;


        QPointF newCenterPos = QPointF(this->scenePos().x() + xOffset, this->scenePos().y() + yOffset);

        line->setLine(QLineF(line->line().p1(), newCenterPos));
    }

}


QVariant Vertex::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if(line != NULL){
        if (change == ItemPositionChange && scene()) {
            QPointF newPos = value.toPointF();

            moveLineToCenter(newPos);
        }
    }

    return QGraphicsItem::itemChange(change, value);
}

