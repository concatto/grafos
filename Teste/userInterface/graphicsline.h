#ifndef GRAPHICSLINE_H
#define GRAPHICSLINE_H
#include "vertex.h"
#include <QGraphicsLineItem>
#include <QMenu>

class Vertex;

class GraphicsLine : public QGraphicsLineItem
{

public:
    enum {Type = UserType + 2};
    GraphicsLine(bool weighted = true);
    int type() const override;
    void setV1(Vertex *v1);
    void setV2(Vertex *v2);
    Vertex* getV1();
    Vertex* getV2();
    int getWeight();
    void setWeight(int weight);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    bool isWeighted() const;

    void tryCentralize();

private:
    Vertex *v1;
    Vertex *v2;
    int weight = 0;
    bool weighted;
};

#endif // GRAPHICSLINE_H
