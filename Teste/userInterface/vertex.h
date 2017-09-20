#ifndef VERTEX_H
#define VERTEX_H
#include <QGraphicsEllipseItem>

class Vertex : public QGraphicsEllipseItem
{
public:
    Vertex(float radius);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    // QGraphicsItem interface
public:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;
};

#endif // VERTEX_H
