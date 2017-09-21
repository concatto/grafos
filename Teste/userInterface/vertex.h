#ifndef VERTEX_H
#define VERTEX_H
#include <QGraphicsEllipseItem>
#include <QMenu>
#include <QString>
#include <QMouseEvent>
#include <QObject>

class Vertex : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    Vertex(float radius, QString name);
    QMenu *getMenu();
    QString getName();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

public:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QMenu *menuList;
    QString name;

signals:
    void drawEdge(Vertex *vertex);

};

#endif // VERTEX_H
