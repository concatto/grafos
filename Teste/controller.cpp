#include "controller.h"
#include <QDebug>

Controller::Controller() : window()
{
    graph = new MGrafo();
    QObject::connect(&window, SIGNAL(addVertex(QString)), graph, SLOT(addVertex(QString)));
    QObject::connect(&window, SIGNAL(removeVertex(QString)), graph, SLOT(removeVertex(QString)));
    QObject::connect(&window, SIGNAL(addConnection(QString,QString,int)), graph, SLOT(addConnection(QString,QString,int)));
    QObject::connect(&window, SIGNAL(removeConnection(QString,QString)), graph, SLOT(removeConnection(QString, QString)));
    window.show();
}