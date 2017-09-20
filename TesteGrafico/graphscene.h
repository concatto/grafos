#ifndef GRAPHSCENE_H
#define GRAPHSCENE_H
#include <QGraphicsScene>
#include <QVector>
#include "vertexitem.h"
#include <QString>


class GraphScene : public QGraphicsScene
{
public:
    GraphScene();
    void addVertex(QString name);
private:
    QVector <VertexItem*> vertices;
};

#endif // GRAPHSCENE_H
