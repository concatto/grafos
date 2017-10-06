#ifndef GRAPHICSLINE_H
#define GRAPHICSLINE_H
#include "vertex.h"
#include <QGraphicsLineItem>
#include <QMenu>

class Vertex;

class GraphicsLine : public QGraphicsLineItem
{
public:
    GraphicsLine();
    int type() const override;
    void setV1(Vertex *v1);
    void setV2(Vertex *v2);
    Vertex* getV1();
    Vertex* getV2();
    int getWeight();
    void setWeight(int weight);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    Vertex *v1;
    Vertex *v2;
    int weight = 0;

};

#endif // GRAPHICSLINE_H
