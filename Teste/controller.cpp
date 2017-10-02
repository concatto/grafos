#include "controller.h"
#include <QDebug>

Controller::Controller() : window()
{
    graph = new MGrafo();
    QObject::connect(&window, SIGNAL(addVertex(QString)), graph, SLOT(addVertex(QString)));
    QObject::connect(&window, SIGNAL(removeVertex(QString)), graph, SLOT(removeVertex(QString)));
    QObject::connect(&window, SIGNAL(addConnection(QString,QString,int)), graph, SLOT(addConnection(QString,QString,int)));
    QObject::connect(&window, SIGNAL(removeConnection(QString,QString)), graph, SLOT(removeConnection(QString, QString)));
    QObject::connect(&window, SIGNAL(performWelshPowell()), graph, SLOT(performWelshPowell()));
    QObject::connect(&window, SIGNAL(performDsatur()), graph, SLOT(performDsatur()));
    QObject::connect(graph, SIGNAL(paintVertices(QVector<int>)), &window, SLOT(paintVertices(QVector<int>)));
    QObject::connect(graph, SIGNAL(paintVertices(QVector<int>)), &window, SLOT(paintVertices(QVector<int>)));
    QObject::connect(&window, SIGNAL(performDijkstra(QString,int)), graph, SLOT(performDijkstra(QString, int)));
    window.show();
}
