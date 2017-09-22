#ifndef GRAPHICSLINE_H
#define GRAPHICSLINE_H
#include <QGraphicsLineItem>


class GraphicsLine : public QGraphicsLineItem
{
public:
    GraphicsLine();
    GraphicsLine(QLineF line);

    // QGraphicsItem interface
public:
    int type() const override;
};

#endif // GRAPHICSLINE_H
