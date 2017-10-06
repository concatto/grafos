#ifndef GRAPHDIALOG_H
#define GRAPHDIALOG_H

#include <QDialog>

namespace Ui {
class GraphDialog;
}

class GraphDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GraphDialog(QWidget *parent = 0);
    ~GraphDialog();

    enum GraphType {
        AdjacencyMatrix, AdjacencyList
    };

    bool isWeighted() const;
    bool isDirected() const;
    GraphType getStructure() const;

private:
    Ui::GraphDialog *ui;
};

#endif // GRAPHDIALOG_H
