/********************************************************************************
** Form generated from reading UI file 'graphdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHDIALOG_H
#define UI_GRAPHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GraphDialog
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *structureGroup;
    QVBoxLayout *verticalLayout;
    QRadioButton *matrixButton;
    QRadioButton *listButton;
    QGroupBox *optionsGroup;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *weightedCheckbox;
    QCheckBox *directedCheckbox;

    void setupUi(QDialog *GraphDialog)
    {
        if (GraphDialog->objectName().isEmpty())
            GraphDialog->setObjectName(QStringLiteral("GraphDialog"));
        GraphDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(GraphDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        structureGroup = new QGroupBox(GraphDialog);
        structureGroup->setObjectName(QStringLiteral("structureGroup"));
        structureGroup->setGeometry(QRect(20, 20, 221, 92));
        verticalLayout = new QVBoxLayout(structureGroup);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        matrixButton = new QRadioButton(structureGroup);
        matrixButton->setObjectName(QStringLiteral("matrixButton"));
        matrixButton->setChecked(true);

        verticalLayout->addWidget(matrixButton);

        listButton = new QRadioButton(structureGroup);
        listButton->setObjectName(QStringLiteral("listButton"));

        verticalLayout->addWidget(listButton);

        optionsGroup = new QGroupBox(GraphDialog);
        optionsGroup->setObjectName(QStringLiteral("optionsGroup"));
        optionsGroup->setGeometry(QRect(20, 130, 221, 92));
        verticalLayout_2 = new QVBoxLayout(optionsGroup);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        weightedCheckbox = new QCheckBox(optionsGroup);
        weightedCheckbox->setObjectName(QStringLiteral("weightedCheckbox"));

        verticalLayout_2->addWidget(weightedCheckbox);

        directedCheckbox = new QCheckBox(optionsGroup);
        directedCheckbox->setObjectName(QStringLiteral("directedCheckbox"));

        verticalLayout_2->addWidget(directedCheckbox);


        retranslateUi(GraphDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), GraphDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GraphDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(GraphDialog);
    } // setupUi

    void retranslateUi(QDialog *GraphDialog)
    {
        GraphDialog->setWindowTitle(QApplication::translate("GraphDialog", "Dialog", Q_NULLPTR));
        structureGroup->setTitle(QApplication::translate("GraphDialog", "Estrutura do Grafo", Q_NULLPTR));
        matrixButton->setText(QApplication::translate("GraphDialog", "&Matriz de Adjac\303\252ncias", Q_NULLPTR));
        listButton->setText(QApplication::translate("GraphDialog", "Lista de Adjac&\303\252ncias", Q_NULLPTR));
        optionsGroup->setTitle(QApplication::translate("GraphDialog", "Op\303\247\303\265es do Grafo", Q_NULLPTR));
        weightedCheckbox->setText(QApplication::translate("GraphDialog", "Ponderado", Q_NULLPTR));
        directedCheckbox->setText(QApplication::translate("GraphDialog", "Orientado", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GraphDialog: public Ui_GraphDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHDIALOG_H
