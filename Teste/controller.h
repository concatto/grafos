#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "mainwindow.h"
#include "grafo.h"
#include "mgrafo.h"
#include "lgrafo.h"
#include "graphdialog.h"
#include <QObject>
#include <QApplication>

class Controller : public QObject
{
    Q_OBJECT
public:
    Controller();
    int exec(QApplication &a);

private:
    MainWindow *window;
    Grafo *graph;
    static Grafo* instantiateGraph(GraphDialog::GraphType structure);
};

#endif // CONTROLLER_H
