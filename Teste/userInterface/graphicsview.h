#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H
#include <QGraphicsView>
#include <QMenu>
#include "graphicsscene.h"
#include <QString>
#include <QObject>

class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    GraphicsView();
    void paintVertices(QVector <int> cores);
    void paintDijkstra(QStack <int> stack);
    // QWidget interface
protected:
    void contextMenuEvent(QContextMenuEvent *event) override;
private:
    QMenu menuList;
    GraphicsScene scene;

public slots:
    void duplicatedEdge();
    void duplicatedVertex();

signals:
    void addVertex(QString str);
    void removeVertex(int id);
    void addConnection(int id1, int id2, int weight);
    void removeConnection(int id1, int id2);
    void performWelshPowell();
    void performDsatur();
    void performDijkstra(int origem, int destino = -1);

};

#endif // GRAPHICSVIEW_H
