#ifndef STRAIGHTEDGE_H
#define STRAIGHTEDGE_H

#include <QGraphicsPathItem>
#include <QPainter>
#include "edge.h"
#include "edgeinterface.h"

class RegularEdge : public QGraphicsPathItem, public EdgeInterface
{
private:
    Edge model;
public:
    enum { Type = Edge::Type };
    RegularEdge(Edge edge);

    void setLine(const QPointF& start, const QPointF& end);

    virtual int type() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    virtual Edge getModel() override;
    virtual void setModel(Edge model) override;
    virtual void centralize() override;
    virtual QGraphicsItem* getItem() override;
    virtual void setStyle(Qt::GlobalColor color, int width) override;
};

#endif // STRAIGHTEDGE_H
