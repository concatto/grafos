#ifndef EDGEINTERFACE_H
#define EDGEINTERFACE_H

#include <QGraphicsItem>
#include "edge.h"

class Edge;

class EdgeInterface
{
public:
    virtual void centralize() = 0;
    virtual QGraphicsItem* getItem() = 0;
    virtual Edge getModel() = 0;
    virtual void setModel(Edge model) = 0;
};

#endif // EDGEINTERFACE_H
