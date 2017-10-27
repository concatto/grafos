#ifndef VERTEX_H
#define VERTEX_H
#include <QGraphicsEllipseItem>
#include <QMenu>
#include <QString>
#include <QMouseEvent>
#include <QObject>
#include "edge.h"
#include "edgeinterface.h"
#include <QVector>

class Edge;
class EdgeInterface;

//struct Line {
//    Line(GraphicsLine *line, bool isP1){
//        this->line = line;
//        this->isP1 = isP1;
//    }
//    GraphicsLine *line;
//    bool isP1;
//};

class Vertex : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    enum { Type = UserType + 1};

    Vertex(float radius, QString name);
    QString getName();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool addConnection(EdgeInterface *line);
    int type() const override;
    void removeConnection(EdgeInterface *line);
    void removeConnections();
    void print(); //Temp, only for debugging
    void paintEdge(int vertice = -1);
    int getId();

    void handleMoveEvent(QGraphicsSceneMouseEvent *event);
//    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    void setId(int value);
    QPointF getCenter() const;


    bool getPressed() const;
    void setPressed(bool value);

    float getRadius() const;
    bool hasLine(int origin, int destination) const;

    const QVector<EdgeInterface*>& getLines() const;

private:
    float radius;
    QString name;
    QVector<EdgeInterface*> lines;
    bool compareLines(Edge *l1, Edge *l2);
    void alignEdges();
    int id;
    static int indexCounter;
    bool pressed;

signals:
    void mousePressed(Vertex *vertex);


    // QGraphicsItem interface
protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;


};

#endif // VERTEX_H
