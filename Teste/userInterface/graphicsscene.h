#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H
#include <QGraphicsScene>
#include <QVector>
#include "vertex.h"
#include <QString>
#include <QObject>
#include <QGraphicsItem>
#include "graphicsline.h"

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    GraphicsScene();
    void addVertex(QString name, QPointF pos);
    void setLine(Vertex *item);

private:
    QVector <Vertex*> vertices;
    bool controle_aresta;
    Vertex *curr_vertex;
    GraphicsLine *curr_line;
    //    QLineF line;

public slots:
    void drawEdge(Vertex *vertex);

signals:
    void addConnection(QString name1, QString name2, int weight = 1);

//    // QGraphicsScene interface
//protected:
//    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // GRAPHICSSCENE_H
