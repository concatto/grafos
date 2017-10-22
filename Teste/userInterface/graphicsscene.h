#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H
#include <QGraphicsScene>
#include <QVector>
#include "vertex.h"
#include <QString>
#include <QObject>
#include <QGraphicsItem>
#include "graphicsline.h"
#include "grafo.h"
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
    void createLine(Vertex *item, bool isDirected, bool isWeighted);
    void print(); //temp, only for debugging
    void paintVertices(QVector <int> cores, QBrush *brush = NULL);
    void paintPath(QVector<Arco> stack);
    void prepareDijkstra(Vertex *item);
    void keyPressEvent(QKeyEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void removeCurrentLine();

    template <class T>
    T* findItem(const QPointF &point) {
        QGraphicsItem* item = itemAt(point, QTransform());
        if (item == nullptr || item->type() != T::Type) {
            return nullptr;
        }
        return dynamic_cast<T*>(item);
    }

    int getTypeOfItemAt(QPointF point);
    void finishConnectionCreation(int id1, int id2, int weight);
    void paintSequence(QVector<int> sequence);
    GraphicsLine* findLine(int id1, int id2);
    Vertex* getVertex(int id);

private:
    Vertex* movingVertex = nullptr;

    QVector <Vertex*> vertices;
    bool addingEdge;
    Vertex *sourceVertex = nullptr;
    GraphicsLine *currentLine = nullptr;
    void sleep(int msec);
    bool performingDijkstra;
    void addLine(Vertex *vertex);

    void executeSecondClickAction(Vertex *vertex);
    void resetControlVaraibles();
    void repaintViews();

signals:
    void addConnection(int id1, int id2);
    void performDijkstra(int origem, int destino = -1);
    void resetCursor();
};

#endif // GRAPHICSSCENE_H
