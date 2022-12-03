#include "mainwindow.h"
#include "ui_mainwindow.h"

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

    _model->initTable(6);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tableInitialized()
{
    _table.clear();
    while (!ui->tableLayout->children().isEmpty())
    {
        auto firstChildObject = ui->tableLayout->children()[0];
        auto firstChildWidget = qobject_cast<QWidget*>(firstChildObject);
        if (firstChildWidget)
        {
            ui->tableLayout->removeWidget(firstChildWidget);
        }
    }

    int modelTableSize = _model->getSize();
    int size = width() / modelTableSize;
    for (int i = 0; i < modelTableSize; ++i)
    {
        QVector<XOWidget*> row;
        for (int j = 0; j < modelTableSize; ++j)
        {
            XOWidget* newWidget = new XOWidget();
            newWidget->setFixedSize(QSize(size, size));
            connect(newWidget, &XOWidget::clicked, this, [=](){ _model->checkTable(i,j); });
            row.append(newWidget);
            ui->tableLayout->addWidget(newWidget, i, j, Qt::AlignCenter);
        }
        _table.append(row);
    }
}

void MainWindow::on_tableChanged(int x, int y, Player playerSelected)
{
    _table[x][y]->setType(playerSelected);
}

void MainWindow::on_gameWon(Player player)
{
    QMessageBox mb(this);
    mb.exec();
    int modelTableSize = _model->getSize();
    for (int i = 0; i < modelTableSize; ++i)
    {
        for (int j = 0; j < modelTableSize; ++j)
        {
            disconnect(_table[i][j], &XOWidget::clicked, this, nullptr);
        }
    }
}

