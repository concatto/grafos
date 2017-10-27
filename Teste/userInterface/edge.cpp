#include "edge.h"
#include <QDebug>

Edge::Edge(bool directed, bool weighted) : directed(directed), weighted(weighted)
{
    this->v1 = NULL;
    this->v2 = NULL;
}

void Edge::setV1(Vertex *v1)
{
    this->v1 = v1;
}

void Edge::setV2(Vertex *v2)
{
    this->v2 = v2;
}

Vertex *Edge::getV1()
{
    return v1;
}

Vertex *Edge::getV2()
{
    return v2;
}

int Edge::getWeight()
{
    return weight;
}

void Edge::setWeight(int weight)
{
    this->weight = weight;
}

bool Edge::isWeighted() const
{
    return weighted;
}

bool Edge::isDirected() const
{
    return directed;
}
