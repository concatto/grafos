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
    void addVertex(QString name);
    void setLine(Vertex *item);
private:
    QVector <Vertex*> vertices;
    bool controle_aresta;
    QLineF line;
public slots:
    void drawEdge(Vertex *vertex);

//    // QGraphicsScene interface
//protected:
//    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // GRAPHICSSCENE_H
