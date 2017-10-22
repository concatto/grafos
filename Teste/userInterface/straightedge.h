#ifndef STRAIGHTEDGE_H
#define STRAIGHTEDGE_H

#include <QGraphicsLineItem>
#include "graphicsline.h"

class StraightEdge : public QGraphicsLineItem, public GraphicsLine
{
public:
    int type() const override;
    StraightEdge(bool isDirected, bool isWeighted);

    virtual void setCustomPen(QPen pen) override;
    virtual void tryCentralize() override;
    virtual void setEndpoints(QPointF a, QPointF b) override;
    virtual QGraphicsItem* item() override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // STRAIGHTEDGE_H
