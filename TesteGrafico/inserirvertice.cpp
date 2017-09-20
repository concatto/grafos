#include "inserirvertice.h"
#include "ui_inserirvertice.h"

InserirVertice::InserirVertice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InserirVertice)
{
    ui->setupUi(this);
}

InserirVertice::~InserirVertice()
{
    delete ui;
}
