#include "controller.h"
#include "graphdialog.h"
#include <QDebug>

Controller::Controller()
{
    GraphDialog dialog;
    if (dialog.exec() == GraphDialog::Accepted) {
        qDebug() << "Tipo: " << dialog.getStructure() << "\n";
        qDebug() << "Ponderado: " << dialog.isWeighted() << "\n";
        qDebug() << "Dirigido: " << dialog.isDirected() << "\n";
        (dialog.getStructure() == GraphDialog::GraphType::AdjacencyList ? graph = new LGrafo() : graph = new MGrafo());
        window = new MainWindow(dialog.isWeighted(), dialog.isDirected());

        QObject::connect(window, SIGNAL(addVertex(QString)), graph, SLOT(addVertex(QString)));
        QObject::connect(window, SIGNAL(removeVertex(int)), graph, SLOT(removeVertex(int)));
        QObject::connect(window, SIGNAL(addConnection(int,int,int)), graph, SLOT(addConnection(int,int,int)));
        QObject::connect(window, SIGNAL(removeConnection(int,int)), graph, SLOT(removeConnection(int, int)));
        QObject::connect(window, SIGNAL(performWelshPowell()), graph, SLOT(performWelshPowell()));
        QObject::connect(window, SIGNAL(performDsatur()), graph, SLOT(performDsatur()));
        QObject::connect(graph, SIGNAL(paintVertices(QVector<int>)), window, SLOT(paintVertices(QVector<int>)));
        QObject::connect(graph, SIGNAL(paintVertices(QVector<int>)), window, SLOT(paintVertices(QVector<int>)));
        QObject::connect(window, SIGNAL(performDijkstra(int,int)), graph, SLOT(performDijkstra(int, int)));
        QObject::connect(graph, SIGNAL(paintDijkstra(QStack<int>)), window, SLOT(paintDijkstra(QStack<int>)));
        window->show();
    }

}
