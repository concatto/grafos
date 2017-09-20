#include "controller.h"
#include <QDebug>

Controller::Controller() : window()
{
    graph = new MGrafo();
    QObject::connect(&window, SIGNAL(addVertex(QString)), graph, SLOT(addVertex(QString)));
    window.show();
}
