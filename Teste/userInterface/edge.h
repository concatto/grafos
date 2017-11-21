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
    static const int NoFlow = -1;

    Edge(bool directed = false, bool weighted = true);
    void setV1(Vertex *v1);
    void setV2(Vertex *v2);
    Vertex* getV1();
    Vertex* getV2();
    int getWeight();
    void setWeight(int weight);
    void setFlow(int flow);

    bool isWeighted() const;
    bool isDirected() const;
    bool hasFlow() const;
    QString format() const;

protected:
    Vertex *v1;
    Vertex *v2;
    int weight = 0;
    int flow = NoFlow;
    bool weighted;
    bool directed;
};

#endif // GRAPHICSLINE_H
