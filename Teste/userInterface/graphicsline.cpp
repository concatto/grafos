#include "graphicsline.h"
#include <QPainter>
#include <QPen>
#include <QDebug>
#include <math.h>
#define M_PI 3.14159265358979323846

GraphicsLine::GraphicsLine(bool directed, bool weighted)
    : QGraphicsLineItem(), directed(directed), weighted(weighted)
{
    this->v1 = NULL;
    this->v2 = NULL;
}

int GraphicsLine::type() const
{
    return Type;
}

void GraphicsLine::setV1(Vertex *v1)
{
    this->v1 = v1;
}

void GraphicsLine::setV2(Vertex *v2)
{
    this->v2 = v2;
}

Vertex *GraphicsLine::getV1()
{
    return v1;
}

Vertex *GraphicsLine::getV2()
{
    return v2;
}

int GraphicsLine::getWeight()
{
    return weight;
}

void GraphicsLine::setWeight(int weight)
{
    this->weight = weight;
}

bool GraphicsLine::isWeighted() const
{
    return weighted;
}
