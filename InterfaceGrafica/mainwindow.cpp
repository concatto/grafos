#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <cstdlib>
#include <QInputDialog>
#include <QMessageBox>

using namespace std;

MainWindow::MainWindow(Grafo &grafo, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    grafo(grafo)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_botao_clicked()
{
    QString s = QInputDialog::getText(this, "Janela de teste", "Digite qualquer coisa");
    QMessageBox::information(this, "Informação", s);
}
