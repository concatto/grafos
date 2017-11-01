#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H
#include <QGraphicsView>
#include <QMenu>
#include "graphicsscene.h"
#include <QString>
#include "grafo.h"
#include "edgeinterface.h"
#include <QObject>

class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    GraphicsView(bool isWeighted, bool isDirected);
    void paintVertices(QVector <int> colors);
    void paintPath(QVector<Arco> path);
    void createVertex(QString name);
    void createConnection(int id1, int id2, int weight);
    void destroyVertex(int id);
    void destroyConnection(int id1, int id2);
    void cancelConnection();
    void displayMessageBox(QString message);

protected:
    void contextMenuEvent(QContextMenuEvent *event) override;

private:
    QPointF storedMousePosition;
    QMenu viewMenuList;
    QMenu vertexMenuList;
    QMenu lineMenuList;
    GraphicsScene scene;
    bool isWeighted;
    bool isDirected;

    void setViewCursor(QCursor cursor);
    void storeMousePosition(QPointF position);
    QPointF consumeMousePosition();
    int showMenu(QMenu &menu);
    void handleVertexCreation();
    void handleVertexRemoval(Vertex *vertex);

public slots:
    void resetCursor();    
    void askConnectionWeight(int id1, int id2);

signals:
    void addVertex(QString str);
    void addConnection(int id1, int id2, int weight);
    void removeVertex(int id);
    void removeConnection(int id1, int id2);
    void performWelshPowell();
    void performDsatur();
    void performDijkstra(int origem, int destino = -1);
    void printGraph();
    void performKruskal();
    void performPrim(int id);
    void performPlanarityCheck();
};

#endif // GRAPHICSVIEW_H
