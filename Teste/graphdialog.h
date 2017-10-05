#ifndef GRAPHDIALOG_H
#define GRAPHDIALOG_H

#include <QDialog>

namespace Ui {
class GraphDialog;
}

enum GraphType {
    AdjacencyMatrix, AdjacencyList
};

class GraphDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GraphDialog(QWidget *parent = 0);
    ~GraphDialog();

    bool isWeighted() const;
    bool isDirected() const;
    GraphType getStructure() const;

private:
    Ui::GraphDialog *ui;
};

#endif // GRAPHDIALOG_H
