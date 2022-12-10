#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gomokumodel.h"
#include "xowidget.h"

#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_tableInitialized();
    void on_tableChanged(int x, int y, Player playerSelected);
    void on_gameWon(Player player);
    void on_newGameTriggered();
    void on_saveGameTriggered();
    void on_loadGameTriggered();

private:

    void resetButtonsConnections();

private:
    Ui::MainWindow *ui;
    GomokuModel* _model;
    int _size;

    QVector<QVector<XOWidget*>> _table;
};
#endif // MAINWINDOW_H
