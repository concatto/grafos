#ifndef GRAPHICSLINE_H
#define GRAPHICSLINE_H
#include "vertex.h"
#include <QGraphicsItem>
#include <QMenu>
#include <QMetaType>

class Vertex; // Forward declaration (circular dependency)

class Edge
{
public:
    enum { Type = QGraphicsItem::UserType + 2 };

    Edge(bool directed = false, bool weighted = true);
    void setV1(Vertex *v1);
    void setV2(Vertex *v2);
    Vertex* getV1();
    Vertex* getV2();
    int getWeight();
    void setWeight(int weight);

    bool isWeighted() const;
    bool isDirected() const;

protected:
    Vertex *v1;
    Vertex *v2;
    int weight = 0;
    bool weighted;
    bool directed;
};

Q_DECLARE_METATYPE(Edge) // Qt witchcraft, allows the usage of QVariant

#endif // GRAPHICSLINE_H
