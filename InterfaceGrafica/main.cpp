#include "mainwindow.h"
#include "dialogografo.h"
#include <QApplication>
#include "grafo.h"
#include "mgrafo.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DialogoGrafo dg;
    dg.show();

    MGrafo g;
    MainWindow w(g);
    w.show();

    return a.exec();
}
