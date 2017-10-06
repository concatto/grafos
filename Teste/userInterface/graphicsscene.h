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
    void setLine(Vertex *item, bool isWeighted);
    void print(); //temp, only for debugging
    void paintVertices(QVector <int> cores, QBrush *brush = NULL);
    void paintDijkstra(QStack <int> stack);
    void setDijkstra(Vertex *item);
    void keyPressEvent(QKeyEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    Vertex* movingVertex = nullptr;

    QVector <Vertex*> vertices;
    bool controle_aresta;
    Vertex *curr_vertex = nullptr;
    GraphicsLine *curr_line = nullptr;
    void sleep(int msec);
    bool controle_dijkstra;
    //    QLineF line;

    Vertex *findVertex(const QPointF &point);
public slots:
    void mousePressed(Vertex *vertex);

signals:
    void addConnection(int id1, int id2, int weight = 1);
    void duplicatedEdge();
    void duplicatedVertex();
    void performDijkstra(int origem, int destino = -1);
    void resetCursor();

};

#endif // GRAPHICSSCENE_H
