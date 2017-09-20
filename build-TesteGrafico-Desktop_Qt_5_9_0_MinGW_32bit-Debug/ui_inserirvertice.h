/********************************************************************************
** Form generated from reading UI file 'inserirvertice.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERIRVERTICE_H
#define UI_INSERIRVERTICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_InserirVertice
{
public:

    void setupUi(QDialog *InserirVertice)
    {
        if (InserirVertice->objectName().isEmpty())
            InserirVertice->setObjectName(QStringLiteral("InserirVertice"));
        InserirVertice->resize(400, 300);

        retranslateUi(InserirVertice);

        QMetaObject::connectSlotsByName(InserirVertice);
    } // setupUi

    void retranslateUi(QDialog *InserirVertice)
    {
        InserirVertice->setWindowTitle(QApplication::translate("InserirVertice", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InserirVertice: public Ui_InserirVertice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERIRVERTICE_H
