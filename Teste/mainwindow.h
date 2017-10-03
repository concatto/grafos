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
    void removeVertex(int id);
    void addConnection(int id1, int id2, int weight = 1);
    void removeConnection(int id1, int id2);
    void performWelshPowell();
    void performDsatur();
    void performDijkstra(int origem, int destino = -1);

public slots:
    void paintVertices(QVector<int> cores);
    void paintDijkstra(QStack <int> stack);

private:
    GraphicsView view;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
