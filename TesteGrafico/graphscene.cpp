#include "graphscene.h"
#include <QDebug>

GraphScene::GraphScene() : QGraphicsScene()
{

}

void GraphScene::addVertex(QString name)
{
    qDebug()<<"sup fella";
    VertexItem *vertex = new VertexItem(30);
    vertices.append(vertex);
    addItem(vertices.back());
}
