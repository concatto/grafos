#ifndef GRAPHENTITY_H
#define GRAPHENTITY_H

#include <QGraphicsItem>

class GraphEntity
{
public:
    enum Type {Vertex, Edge};

    GraphEntity();
    virtual Type getType() = 0;
};

#endif // GRAPHENTITY_H
