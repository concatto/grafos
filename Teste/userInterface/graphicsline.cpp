#include "graphicsline.h"

GraphicsLine::GraphicsLine() : QGraphicsLineItem()
{

}

GraphicsLine::GraphicsLine(QLineF line) : QGraphicsLineItem(line)
{

}


int GraphicsLine::type() const
{
    return 2;
}
