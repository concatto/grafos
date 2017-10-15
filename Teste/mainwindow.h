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
    explicit MainWindow(bool isWeighted, bool isDirected, QWidget *parent = 0);
    ~MainWindow();

    GraphicsView& getView();
    void showError(QString message, QString title = "Erro");

public slots:
    void paintVertices(QVector<int> cores);
    void paintDijkstra(QStack <int> stack);

private:
    GraphicsView view;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
