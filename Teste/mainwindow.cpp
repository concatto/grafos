#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), view()
{
    ui->setupUi(this);
//    QObject::connect(&view, SIGNAL(addVertexRequest(QString)), this, SLOT(addVertexRequest(QString)));
    QObject::connect(&view, SIGNAL(addVertex(QString)), this, SIGNAL(addVertex(QString)));
    QObject::connect(&view, SIGNAL(removeVertex(QString)), this, SIGNAL(removeVertex(QString)));
    QObject::connect(&view, SIGNAL(addConnection(QString,QString,int)), this, SIGNAL(addConnection(QString,QString,int)));
    QObject::connect(&view, SIGNAL(removeConnection(QString,QString)), this, SIGNAL(removeConnection(QString,QString)));
    QObject::connect(&view, SIGNAL(performWelshPowell()), this, SIGNAL(performWelshPowell()));
    QObject::connect(&view, SIGNAL(performDsatur()), this, SIGNAL(performDsatur()));
    QObject::connect(&view, SIGNAL(performDijkstra(QString,int)), this, SIGNAL(performDijkstra(QString,int)));
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
