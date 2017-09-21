#include "graphicsscene.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QTransform>
#include <QGraphicsView>


GraphicsScene::GraphicsScene()
{
    setSceneRect(0, 0, 740, 340);
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
    controle_aresta = true;
    line.setP1(item->pos());
}

void GraphicsScene::drawEdge(Vertex *vertex)
{
    if(controle_aresta){
        line.setP2(vertex->pos());
//        addLine(GraphicsLine(line));
        GraphicsLine *gline = new GraphicsLine(line);
        addItem(gline);
        controle_aresta = false;
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
