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
    // QWidget interface
protected:
    void contextMenuEvent(QContextMenuEvent *event) override;
private:
    QMenu menuList;
    GraphicsScene scene;

signals:
    void addVertex(QString str);
    void removeVertex(QString str);

};

#endif // GRAPHICSVIEW_H
