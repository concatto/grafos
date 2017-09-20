#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H
#include <QGraphicsView>
#include <QMenu>
#include "graphscene.h"


class GraphView : public QGraphicsView
{
public:
    GraphView();

    // QWidget interface
protected:
    void contextMenuEvent(QContextMenuEvent *event) override;
private:
    QMenu menuList;
    GraphScene scene;
};

#endif // GRAPHVIEW_H
