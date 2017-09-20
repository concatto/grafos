#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "userInterface/graphicsview.h"
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void addVertex(QString str);

private:
    GraphicsView view;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
