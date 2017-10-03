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
    void removeVertex(QString str);
    void addConnection(QString name1, QString name2, int weight = 1);
    void removeConnection(QString name1, QString name2);
    void performWelshPowell();
    void performDsatur();
    void performDijkstra(QString name1, QString name2 = NULL);

public slots:
    void paintVertices(QVector<int> cores);
    void paintDijkstra(QStack <int> stack);

private:
    GraphicsView view;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
