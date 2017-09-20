#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->layout()->addWidget(&view);

    view.setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
}

MainWindow::~MainWindow()
{
    delete ui;
}
