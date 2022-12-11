#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "newgamedialog.h"
#include "filemanager.h"

#include <QFileDialog>
#include <QLabel>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _model = new GomokuModel(this);

    connect(_model, &GomokuModel::tableInitialized, this, &MainWindow::on_tableInitialized);
    connect(_model, &GomokuModel::tableChanged, this, &MainWindow::on_tableChanged);
    connect(_model, &GomokuModel::gameWon, this, &MainWindow::on_gameWon);
    connect(_model, &GomokuModel::gameOver, this, &MainWindow::on_draw);
    connect(_model, &GomokuModel::currentPlayerChanged, this, &MainWindow::on_currentPlayerChanged);
    connect(_model, &GomokuModel::fileError, this, &MainWindow::on_fileError);

    _size = width() < height() ? width() : height();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tableInitialized()
{
    _table.clear();
    while (auto item = ui->tableLayout->takeAt(0))
    {
        delete item->widget();
    }

    int modelTableSize = _model->getSize();
    int size = _size / modelTableSize;
    auto table = _model->getTable();
    for (int i = 0; i < modelTableSize; ++i)
    {
        QVector<XOWidget*> row;
        for (int j = 0; j < modelTableSize; ++j)
        {
            XOWidget* newWidget = new XOWidget();
            newWidget->setFixedSize(QSize(size, size));
            newWidget->setType(table[i][j]);
            connect(newWidget, &XOWidget::clicked, this, [=](){ _model->checkTable(i,j); });
            row.append(newWidget);
            ui->tableLayout->addWidget(newWidget, i, j, Qt::AlignCenter);
        }
        _table.append(row);
    }
    ui->actionSave_Game->setEnabled(true);
}

void MainWindow::on_tableChanged(int x, int y, Player playerSelected)
{
    _table[x][y]->setType(playerSelected);
}

void MainWindow::on_gameWon(Player player)
{
    QMessageBox::information(this, "Won", "Congratulations! Player " + playerToString(player) + " won.");
    ui->actionSave_Game->setEnabled(false);
    resetButtonsConnections();
    _model->initTable(_model->getSize());
}

void MainWindow::on_draw()
{
    QMessageBox::information(this, "Draw", "Game over. No one wins.");
    ui->actionSave_Game->setEnabled(false);
    resetButtonsConnections();
    _model->initTable(_model->getSize());
}

void MainWindow::on_newGameTriggered()
{
    NewGameDialog dialog;
    if (dialog.exec() == QDialog::Accepted)
    {
        int size = dialog.getCheckedSize();
        _model->initTable(size);
    }
}

void MainWindow::on_saveGameTriggered()
{
    QFileDialog saveDialog(this, "Save Game", "./", "Save Files (*.sav)");
    saveDialog.setAcceptMode(QFileDialog::AcceptSave);
    saveDialog.setFileMode(QFileDialog::AnyFile);
    if (saveDialog.exec() == QDialog::Accepted)
    {
        IPersistence* manager = new Filemanager(this);
        _model->save(saveDialog.selectedFiles()[0], manager);
    }
}

void MainWindow::on_loadGameTriggered()
{
    QFileDialog loadDialog(this, "Load Game", "./", "Save Files (*.sav)");
    loadDialog.setAcceptMode(QFileDialog::AcceptOpen);
    loadDialog.setFileMode(QFileDialog::AnyFile);
    if (loadDialog.exec() == QDialog::Accepted)
    {
        IPersistence* manager = new Filemanager(this);
        _model->load(loadDialog.selectedFiles()[0], manager);
    }
}

void MainWindow::on_currentPlayerChanged()
{
    ui->statusBar->showMessage("Current Player: " + playerToString(_model->getCurrentPlayer()));
}

void MainWindow::on_fileError()
{
    QMessageBox::warning(this, "File Error", "An error occured during file management.");
}

void MainWindow::resetButtonsConnections()
{
    int modelTableSize = _model->getSize();
    for (int i = 0; i < modelTableSize; ++i)
    {
        for (int j = 0; j < modelTableSize; ++j)
        {
            disconnect(_table[i][j], &XOWidget::clicked, this, nullptr);
        }
    }
}

