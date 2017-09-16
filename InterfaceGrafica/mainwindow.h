#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "grafo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Grafo &grafo, QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_botao_clicked();

private:
    Grafo& grafo;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
