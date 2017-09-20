#ifndef VERTEX_H
#define VERTEX_H
#include <QGraphicsEllipseItem>
#include <QMenu>
#include <QString>

class Vertex : public QGraphicsEllipseItem
{
public:
    Vertex(float radius, QString name);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;
    QMenu *getMenu();
    QString getName();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QMenu *menuList;
    QString name;
};

#endif // VERTEX_H
