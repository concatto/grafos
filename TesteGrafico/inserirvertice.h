#ifndef INSERIRVERTICE_H
#define INSERIRVERTICE_H

#include <QDialog>

namespace Ui {
class InserirVertice;
}

class InserirVertice : public QDialog
{
    Q_OBJECT

public:
    explicit InserirVertice(QWidget *parent = 0);
    ~InserirVertice();

private:
    Ui::InserirVertice *ui;
};

#endif // INSERIRVERTICE_H
