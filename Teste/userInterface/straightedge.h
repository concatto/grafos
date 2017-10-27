#ifndef STRAIGHTEDGE_H
#define STRAIGHTEDGE_H

#include <QGraphicsLineItem>
#include <QPainter>
#include "edge.h"
#include "edgeinterface.h"

class StraightEdge : public QGraphicsLineItem, public EdgeInterface
{
private:
    Edge model;
public:
    enum { Type = Edge::Type };
    StraightEdge(Edge edge);

    virtual int type() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    virtual Edge getModel() override;
    virtual void setModel(Edge model) override;
    virtual void centralize() override;
    virtual QGraphicsItem* getItem() override;
};

#endif // STRAIGHTEDGE_H
