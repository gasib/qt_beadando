#include "filemanager.h"

Filemanager::Filemanager(QObject *parent)
    : IPersistence{parent}
{

}

void Filemanager::save(QString filename, GomokuModel &model)
{

}

QVector<QVector<Player> > Filemanager::load(QString filename)
{

}

IPersistence::IPersistence(QObject *parent)
    : QObject(parent)
{

}
