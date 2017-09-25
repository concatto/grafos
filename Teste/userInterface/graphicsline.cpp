#include "graphicsline.h"
#include <QPainter>
#include <QPen>
#include <QDebug>

GraphicsLine::GraphicsLine() : QGraphicsLineItem()
{
    this->v1 = NULL;
    this->v2 = NULL;
    menuList = new QMenu();
    menuList->addAction("Remover conexão");
    setPen(QPen(QBrush(Qt::black), 4));
}

int GraphicsLine::type() const
{
    return 2;
}

QMenu* GraphicsLine::getMenu()
{
    return menuList;
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
