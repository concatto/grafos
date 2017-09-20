#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "mainwindow.h"
#include "grafo.h"
#include "mgrafo.h"
#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
public:
    Controller();

private:
    MainWindow window;
    Grafo *graph;
};

#endif // CONTROLLER_H
