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
    void removeVertex(QString str);
    void addConnection(QString name1, QString name2, int weight);
    void removeConnection(QString name1, QString name2);
    void performWelshPowell();
    void performDsatur();
    void performDijkstra(QString name, int destino = -1);

};

#endif // GRAPHICSVIEW_H
