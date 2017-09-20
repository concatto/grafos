#include "graphicsscene.h"
#include <QDebug>

GraphicsScene::GraphicsScene()
{
    setSceneRect(0, 0, 800, 600);
}

void GraphicsScene::addVertex(QString name)
{
    qDebug()<<"sup fella";
    Vertex *vertex = new Vertex(30, name);
    vertices.append(vertex);
    addItem(vertices.back());
}
