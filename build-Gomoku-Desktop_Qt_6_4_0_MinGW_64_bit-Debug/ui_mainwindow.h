/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Game;
    QAction *actionSave_Game;
    QAction *actionLoad_Game;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *tableLayout;
    QToolBar *toolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionNew_Game = new QAction(MainWindow);
        actionNew_Game->setObjectName("actionNew_Game");
        actionSave_Game = new QAction(MainWindow);
        actionSave_Game->setObjectName("actionSave_Game");
        actionLoad_Game = new QAction(MainWindow);
        actionLoad_Game->setObjectName("actionLoad_Game");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        tableLayout = new QGridLayout();
        tableLayout->setObjectName("tableLayout");
        tableLayout->setSizeConstraint(QLayout::SetDefaultConstraint);

        verticalLayout->addLayout(tableLayout);

        MainWindow->setCentralWidget(centralwidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setMovable(false);
        toolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        toolBar->addAction(actionNew_Game);
        toolBar->addAction(actionSave_Game);
        toolBar->addAction(actionLoad_Game);

        retranslateUi(MainWindow);
        QObject::connect(actionNew_Game, SIGNAL(triggered()), MainWindow, SLOT(on_newGameTriggered()));
        QObject::connect(actionSave_Game, SIGNAL(triggered()), MainWindow, SLOT(on_saveGameTriggered()));
        QObject::connect(actionLoad_Game, SIGNAL(triggered()), MainWindow, SLOT(on_loadGameTriggered()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gomoku Game", nullptr));
        actionNew_Game->setText(QCoreApplication::translate("MainWindow", "New Game", nullptr));
        actionSave_Game->setText(QCoreApplication::translate("MainWindow", "Save Game", nullptr));
        actionLoad_Game->setText(QCoreApplication::translate("MainWindow", "Load Game", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
