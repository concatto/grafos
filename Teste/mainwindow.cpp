#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLayout>
#include <QStack>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), view()
{
    ui->setupUi(this);
//    QObject::connect(&view, SIGNAL(addVertexRequest(QString)), this, SLOT(addVertexRequest(QString)));
    QObject::connect(&view, SIGNAL(addVertex(QString)), this, SIGNAL(addVertex(QString)));
    QObject::connect(&view, SIGNAL(removeVertex(int)), this, SIGNAL(removeVertex(int)));
    QObject::connect(&view, SIGNAL(addConnection(int,int,int)), this, SIGNAL(addConnection(int,int,int)));
    QObject::connect(&view, SIGNAL(removeConnection(int, int)), this, SIGNAL(removeConnection(int, int)));
    QObject::connect(&view, SIGNAL(performWelshPowell()), this, SIGNAL(performWelshPowell()));
    QObject::connect(&view, SIGNAL(performDsatur()), this, SIGNAL(performDsatur()));
    QObject::connect(&view, SIGNAL(performDijkstra(int, int)), this, SIGNAL(performDijkstra(int, int)));
    ui->centralwidget->layout()->addWidget(&view);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintVertices(QVector<int> cores)
{
    view.paintVertices(cores);
}

void MainWindow::paintDijkstra(QStack<int> stack)
{
    view.paintDijkstra(stack);
}
