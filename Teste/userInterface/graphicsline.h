#ifndef GRAPHICSLINE_H
#define GRAPHICSLINE_H
#include <QGraphicsLineItem>


class GraphicsLine : public QGraphicsLineItem
{
public:
    GraphicsLine();
    GraphicsLine(QLineF line);
};

#endif // GRAPHICSLINE_H
