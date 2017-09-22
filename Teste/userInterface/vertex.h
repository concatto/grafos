#ifndef VERTEX_H
#define VERTEX_H
#include <QGraphicsEllipseItem>
#include <QMenu>
#include <QString>
#include <QMouseEvent>
#include <QObject>
#include "graphicsline.h"

class Vertex : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    Vertex(float radius, QString name);
    QMenu *getMenu();
    QString getName();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void addConnection(GraphicsLine *line, bool p1);

public:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QMenu *menuList;
    QString name;
    bool isP1;
    GraphicsLine *line;

    void moveLineToCenter(QPointF newPos);

signals:
    void drawEdge(Vertex *vertex);


    // QGraphicsItem interface
protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
};

#endif // VERTEX_H
