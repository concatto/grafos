#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLayout>
#include <QStack>
#include <QMessageBox>

MainWindow::MainWindow(bool isWeighted, bool isDirected, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), view(isWeighted, isDirected)
{
    ui->setupUi(this);
    ui->centralwidget->layout()->addWidget(&view);
}

MainWindow::~MainWindow()
{
    delete ui;
}

GraphicsView &MainWindow::getView()
{
    return view;
}

void MainWindow::paintVertices(QVector<int> cores)
{
    view.paintVertices(cores);
}

//void MainWindow::paintDijkstra(QStack<int> stack)
//{
//    view.paint(stack);
//}

void MainWindow::showError(QString message, QString title)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle(title);
    msgBox.setText(message);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}
