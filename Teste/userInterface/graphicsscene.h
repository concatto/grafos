#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H
#include <QGraphicsScene>
#include <QVector>
#include "vertex.h"
#include <QString>
#include <QObject>
#include <QGraphicsItem>
#include "graphicsline.h"
#ifdef Q_OS_WIN
#include <windows.h>
#endif

class GraphicsScene : public QGraphicsScene 
{
    Q_OBJECT
public:
    GraphicsScene();
    bool addVertex(QString name, QPointF pos);
    void removeVertex(Vertex *vertex);
    void setLine(Vertex *item);
    void print(); //temp, only for debugging
    void paintVertices(QVector <int> cores);
    void paintDijkstra(QStack <int> stack);
    void setDijkstra(Vertex *item);

private:
    QVector <Vertex*> vertices;
    bool controle_aresta;
    Vertex *curr_vertex;
    GraphicsLine *curr_line;
    void sleep(int msec);
    bool controle_dijkstra;
    //    QLineF line;

public slots:
    void mousePressed(Vertex *vertex);

signals:
    void addConnection(QString name1, QString name2, int weight = 1);
    void duplicatedEdge();
    void duplicatedVertex();
    void performDijkstra(QString name1, QString name2 = NULL);
};

#endif // GRAPHICSSCENE_H
