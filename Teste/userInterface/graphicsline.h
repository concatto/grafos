#ifndef GRAPHICSLINE_H
#define GRAPHICSLINE_H
#include "vertex.h"
#include <QGraphicsLineItem>
#include <QMenu>

class Vertex;

class GraphicsLine
{

public:
    enum { Type = 65536 + 2 };
    GraphicsLine(bool directed, bool weighted = true);
    void setV1(Vertex *v1);
    void setV2(Vertex *v2);
    Vertex* getV1();
    Vertex* getV2();
    int getWeight();
    void setWeight(int weight);

    bool isWeighted() const;

    virtual void setCustomPen(QPen pen) = 0;
    virtual void setEndpoints(QPointF a, QPointF b) = 0;
    virtual QGraphicsItem* item() = 0;
    virtual void tryCentralize() = 0;

protected:
    Vertex *v1;
    Vertex *v2;
    int weight = 0;
    bool weighted;
    bool directed;
};

#endif // GRAPHICSLINE_H
