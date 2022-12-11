#include "ipersistencemock.h"

#include "../Gomoku/gomokumodel.h"

IPersistenceMock::IPersistenceMock()
{

}

IPersistenceMock::IPersistenceMock(const int size, const QVector<QVector<Player> >& table, const Player current)
{
    loadTestData(size, table, current);
}

void IPersistenceMock::loadTestData(const int size, const QVector<QVector<Player> >& table, const Player current)
{
    _size = size;
    _table = table;
    _current = current;
}

bool IPersistenceMock::save(QString fileName, const GomokuModel *model)
{
    emit saved();
}

bool IPersistenceMock::load(QString fileName, GomokuModel *model)
{
    model->setSize(_size);
    model->setCurrentPlayer(_current);
    model->setTable(_table);
    emit loaded();
}
