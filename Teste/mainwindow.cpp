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
    ui->centralwidget->layout()->addWidget(&view);
    ui->centralwidget->setFixedWidth(800);
    ui->centralwidget->setFixedHeight(600);
}

MainWindow::~MainWindow()
{
    delete ui;
}
