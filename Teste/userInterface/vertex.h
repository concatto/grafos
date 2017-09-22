#ifndef VERTEX_H
#define VERTEX_H
#include <QGraphicsEllipseItem>
#include <QMenu>
#include <QString>
#include <QMouseEvent>
#include <QObject>
#include "graphicsline.h"
#include <QVector>

struct Line {
    Line(GraphicsLine *line, bool isP1){
        this->line = line;
        this->isP1 = isP1;
    }
    GraphicsLine *line;
    bool isP1;
};

class Vertex : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    Vertex(float radius, QString name);
    QMenu *getMenu();
    QString getName();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void addConnection(GraphicsLine *line, bool p1);
    int type() const override;

public:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QMenu *menuList;
    QString name;
//    bool isP1;
//    GraphicsLine *line;
    QVector <Line*> lines;

    void moveLineToCenter(QPointF newPos);

signals:
    void drawEdge(Vertex *vertex);


    // QGraphicsItem interface
protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;


};

#endif // VERTEX_H
