#include "graphicsscene.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QTransform>
#include <QGraphicsView>


GraphicsScene::GraphicsScene()
{
    setSceneRect(0, 0, 740, 340);
    curr_vertex = NULL;
    controle_aresta = false;
//    setBackgroundBrush(QBrush(Qt::red));

}

void GraphicsScene::addVertex(QString name)
{
    Vertex *vertex = new Vertex(50, name);
    vertex->setPos(0, 0);
    vertices.append(vertex);
    addItem(vertices.back());
    QObject::connect(vertex, SIGNAL(drawEdge(Vertex*)), this, SLOT(drawEdge(Vertex*)));
}

void GraphicsScene::setLine( Vertex *item)
{
//    line.setP1(item->pos());
    curr_vertex = item;
    controle_aresta = true;
    curr_line = new GraphicsLine();
    item->addConnection(curr_line, true);
}

void GraphicsScene::drawEdge(Vertex *vertex)
{
    if(controle_aresta){
        addItem(curr_line);
        vertex->addConnection(curr_line, false);
//        curr_vertex->setP2(vertex->pos());
        curr_line = NULL;
        controle_aresta = false;
        emit addConnection(curr_vertex->getName(), vertex->getName());
    }
}


//void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
//    qDebug()<<controle_aresta;
//    if(controle_aresta){
//        if(Vertex *vertex = (Vertex*)itemAt(event->pos(), QTransform())){
//            this->line.setP2(vertex->pos());
//            QGraphicsLineItem *item = new QGraphicsLineItem(line);
//            addItem(item);
//        }
//        controle_aresta = false;
//    }else {
//        qDebug()<<"Vertex: "<<vertices.first()->pos();
//        qDebug()<<"ScenePos: "<<event->scenePos();
//        qDebug()<<"pos: "<<event->pos();
//        if(Vertex *vertex = (Vertex*)itemAt(event->pos(), QTransform())){
//            vertex->mouseMoveEvent(event);

//        }
//    }
//}
