/********************************************************************************
** Form generated from reading UI file 'newgamedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWGAMEDIALOG_H
#define UI_NEWGAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewGameDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout;
    QRadioButton *rb6;
    QRadioButton *rb10;
    QRadioButton *rb14;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewGameDialog)
    {
        if (NewGameDialog->objectName().isEmpty())
            NewGameDialog->setObjectName("NewGameDialog");
        NewGameDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(NewGameDialog);
        verticalLayout->setObjectName("verticalLayout");
        groupBox_2 = new QGroupBox(NewGameDialog);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        rb6 = new QRadioButton(groupBox_2);
        rb6->setObjectName("rb6");

        formLayout->setWidget(0, QFormLayout::LabelRole, rb6);

        rb10 = new QRadioButton(groupBox_2);
        rb10->setObjectName("rb10");

        formLayout->setWidget(1, QFormLayout::LabelRole, rb10);

        rb14 = new QRadioButton(groupBox_2);
        rb14->setObjectName("rb14");

        formLayout->setWidget(2, QFormLayout::LabelRole, rb14);


        verticalLayout_3->addLayout(formLayout);


        verticalLayout->addWidget(groupBox_2);

        buttonBox = new QDialogButtonBox(NewGameDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(NewGameDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, NewGameDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, NewGameDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(NewGameDialog);
    } // setupUi

    void retranslateUi(QDialog *NewGameDialog)
    {
        NewGameDialog->setWindowTitle(QCoreApplication::translate("NewGameDialog", "New Game", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("NewGameDialog", "Table Size", nullptr));
        rb6->setText(QCoreApplication::translate("NewGameDialog", "6x6", nullptr));
        rb10->setText(QCoreApplication::translate("NewGameDialog", "10x10", nullptr));
        rb14->setText(QCoreApplication::translate("NewGameDialog", "14x14", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewGameDialog: public Ui_NewGameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWGAMEDIALOG_H
