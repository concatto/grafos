#ifndef DIALOGOGRAFO_H
#define DIALOGOGRAFO_H

#include <QDialog>

namespace Ui {
class DialogoGrafo;
}

class DialogoGrafo : public QDialog
{
    Q_OBJECT

public:
    explicit DialogoGrafo(QWidget *parent = 0);
    ~DialogoGrafo();

private:
    Ui::DialogoGrafo *ui;
};

#endif // DIALOGOGRAFO_H
