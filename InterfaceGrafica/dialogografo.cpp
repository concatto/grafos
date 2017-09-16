#include "dialogografo.h"
#include "ui_dialogografo.h"

DialogoGrafo::DialogoGrafo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogoGrafo)
{
    ui->setupUi(this);
}

DialogoGrafo::~DialogoGrafo()
{
    delete ui;
}
