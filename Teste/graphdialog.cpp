#include "graphdialog.h"
#include "ui_graphdialog.h"

GraphDialog::GraphDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GraphDialog)
{
    ui->setupUi(this);
}

GraphDialog::~GraphDialog()
{
    delete ui;
}

bool GraphDialog::isWeighted() const
{
    return ui->weightedCheckbox->isChecked();
}

bool GraphDialog::isDirected() const
{
    return ui->directedCheckbox->isChecked();
}

GraphDialog::GraphType GraphDialog::getStructure() const
{
    return ui->listButton->isChecked() ? GraphType::AdjacencyList : GraphType::AdjacencyMatrix;
}


