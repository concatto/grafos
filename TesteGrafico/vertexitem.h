#ifndef VERTEXITEM_H
#define VERTEXITEM_H

#include <QGraphicsEllipseItem>

class VertexItem : public QGraphicsEllipseItem
{
public:
    VertexItem(float radius);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // VERTEXITEM_H
