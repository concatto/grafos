#include "controller.h"
#include <QDebug>

Controller::Controller() : window()
{
    graph = new MGrafo();
    QObject::connect(&window, SIGNAL(addVertex(QString)), graph, SLOT(addVertex(QString)));
    QObject::connect(&window, SIGNAL(removeVertex(int)), graph, SLOT(removeVertex(int)));
    QObject::connect(&window, SIGNAL(addConnection(int,int,int)), graph, SLOT(addConnection(int,int,int)));
    QObject::connect(&window, SIGNAL(removeConnection(int,int)), graph, SLOT(removeConnection(int, int)));
    QObject::connect(&window, SIGNAL(performWelshPowell()), graph, SLOT(performWelshPowell()));
    QObject::connect(&window, SIGNAL(performDsatur()), graph, SLOT(performDsatur()));
    QObject::connect(graph, SIGNAL(paintVertices(QVector<int>)), &window, SLOT(paintVertices(QVector<int>)));
    QObject::connect(graph, SIGNAL(paintVertices(QVector<int>)), &window, SLOT(paintVertices(QVector<int>)));
    QObject::connect(&window, SIGNAL(performDijkstra(int,int)), graph, SLOT(performDijkstra(int, int)));
    QObject::connect(graph, SIGNAL(paintDijkstra(QStack<int>)), &window, SLOT(paintDijkstra(QStack<int>)));
    window.show();
}
