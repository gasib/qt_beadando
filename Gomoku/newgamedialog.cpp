#include "newgamedialog.h"
#include "ui_newgamedialog.h"

NewGameDialog::NewGameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewGameDialog)
{
    ui->setupUi(this);
}

NewGameDialog::~NewGameDialog()
{
    delete ui;
}

int NewGameDialog::getCheckedSize()
{
    int size = 6;
    if (ui->rb10->isChecked())
        size = 10;

    if (ui->rb14->isChecked())
        size = 14;

    return size;
}
