#ifndef SELFLOOP_H
#define SELFLOOP_H

#include <QGraphicsEllipseItem>
#include <QPainter>
#include "edgeinterface.h"
#include "edge.h"

class SelfLoop : public QGraphicsEllipseItem, public EdgeInterface
{
private:
    Edge model;

public:
    enum { Type = Edge::Type };

    SelfLoop(Edge edge);

    virtual int type() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    virtual Edge getModel() override;
    virtual void setModel(Edge model) override;
    virtual void centralize() override;
    virtual QGraphicsItem* getItem() override;
};

#endif // SELFLOOP_H
