#include "gomokumodel.h"

GomokuModel::GomokuModel(QObject *parent)
    : QObject{parent}
{

}

void GomokuModel::checkTable(int x, int y)
{
    if (!canBeChecked(x,y))
        return;

    _table[x][y] = _currentPlayer;
    emit tableChanged(x, y, _currentPlayer);
    if (isAllChecked())
    {
        emit gameOver();
        return;
    }
    if (maxNeighboring(x, y) >= 5)
    {
        gameWon(_currentPlayer);
        return;
    }
    _currentPlayer = _currentPlayer == Player::X ? Player::O : Player::X;
}

int GomokuModel::getSize() const
{
    return _tableSize;
}

void GomokuModel::initTable(int size)
{
    _currentPlayer = Player::X;
    _maxNeighborPlayerX = 0;
    _maxNeighborPlayerO = 0;
    _tableSize = size;
    _table.clear();
    for (int i = 0; i < size; ++i)
    {
        QVector<Player> newRow;
        for (int j = 0; j < size; ++j)
        {
            newRow.append(Player::None);
        }
        _table.append(newRow);
    }
    emit tableInitialized();
}

bool GomokuModel::canBeChecked(int x, int y)
{
    if (x < 0 || x >= _tableSize || y < 0 || y >= _tableSize || _table[x][y] != Player::None)
    {
        emit invalidPosition(x, y);
        return false;
    }
    return true;
}

int GomokuModel::maxNeighboring(int x, int y)
{
    return std::max({checkInDirection(x+1, y, 1, 0, 1, _table[x][y]),
                     checkInDirection(x-1, y, -1, 0, 1, _table[x][y]),
                     checkInDirection(x, y+1, 0, 1, 1, _table[x][y]),
                     checkInDirection(x, y-1, 0, -1, 1, _table[x][y]),
                     checkInDirection(x+1, y-1, 1, -1, 1, _table[x][y]),
                     checkInDirection(x-1, y-1, -1, -1, 1, _table[x][y]),
                     checkInDirection(x+1, y+1, 1, 1, 1, _table[x][y]),
                     checkInDirection(x-1, y+1, -1, 1, 1, _table[x][y])
                   });
}

int GomokuModel::checkInDirection(int x, int y, int dirx, int diry, int current, Player player)
{
    if (x < 0 || x >= _tableSize || y < 0 || y >= _tableSize)
        return current;

    if (_table[x][y] == player)
        return checkInDirection(x+dirx, y+diry, dirx, diry, current+1, player);

    return current;
}

bool GomokuModel::isAllChecked()
{
    for (int i = 0; i < _tableSize; ++i)
    {
        for (int j = 0; j < _tableSize; ++j)
        {
            if (_table[i][j] == Player::None)
                return false;
        }
    }
    return true;
}
