#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H
#include <QGraphicsScene>
#include <QVector>
#include "vertex.h"
#include <QString>


class GraphicsScene : public QGraphicsScene
{
public:
    GraphicsScene();
    void addVertex(QString name);
private:
    QVector <Vertex*> vertices;
};

#endif // GRAPHICSSCENE_H
