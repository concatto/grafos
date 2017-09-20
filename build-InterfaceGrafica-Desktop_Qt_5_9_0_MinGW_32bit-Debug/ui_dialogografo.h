/********************************************************************************
** Form generated from reading UI file 'dialogografo.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOGRAFO_H
#define UI_DIALOGOGRAFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_DialogoGrafo
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;

    void setupUi(QDialog *DialogoGrafo)
    {
        if (DialogoGrafo->objectName().isEmpty())
            DialogoGrafo->setObjectName(QStringLiteral("DialogoGrafo"));
        DialogoGrafo->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogoGrafo);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(DialogoGrafo);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 60, 273, 50));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        horizontalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        horizontalLayout->addWidget(radioButton_2);


        retranslateUi(DialogoGrafo);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogoGrafo, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogoGrafo, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogoGrafo);
    } // setupUi

    void retranslateUi(QDialog *DialogoGrafo)
    {
        DialogoGrafo->setWindowTitle(QApplication::translate("DialogoGrafo", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("DialogoGrafo", "Tipo de estrutura", Q_NULLPTR));
        radioButton->setText(QApplication::translate("DialogoGrafo", "Lista de Adjac\303\252ncias", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("DialogoGrafo", "Matriz de Adjac\303\252ncias", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoGrafo: public Ui_DialogoGrafo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOGRAFO_H
