#include "graphicsscene.h"
#include <QDebug>

GraphicsScene::GraphicsScene()
{

}

void GraphicsScene::addVertex(QString name)
{
    qDebug()<<"sup fella";
    Vertex *vertex = new Vertex(30, name);
    vertices.append(vertex);
    addItem(vertices.back());
}
