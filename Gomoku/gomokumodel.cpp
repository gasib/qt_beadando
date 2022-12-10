#include "gomokumodel.h"

#include <QRandomGenerator>

GomokuModel::GomokuModel(QObject *parent)
    : QObject{parent}
{

}

GomokuModel::~GomokuModel()
{

}

void GomokuModel::checkTable(int x, int y)
{
    if (!canBeChecked(x,y))
        return;

    _table[x][y] = _currentPlayer;
    reloadMaxNeighbor(_currentPlayer);
    emit tableChanged(x, y, _currentPlayer);
    if (isAllChecked())
    {
        emit gameOver();
        return;
    }
    if (_maximumNeighbor[_currentPlayer] >= 5)
    {
        emit gameWon(_currentPlayer);
        return;
    }
    if (_maximumNeighbor[_currentPlayer] >= 3)
    {
        mess(_currentPlayer);
    }
    _playerCoordinates[_currentPlayer].append(QPair<int,int>(x,y));
    _currentPlayer = _currentPlayer == Player::X ? Player::O : Player::X;
    emit currentPlayerChanged();
}

void GomokuModel::setCurrentPlayer(Player player)
{
    _currentPlayer = player;
    emit currentPlayerChanged();
}

void GomokuModel::setTable(QVector<QVector<Player> > newTable)
{
    if (newTable.size() != _tableSize)
        _tableSize = newTable.size();

    _table = newTable;
    emit tableInitialized();
}

void GomokuModel::initTable(int size)
{
    _currentPlayer = Player::X;
    emit currentPlayerChanged();
    _maximumNeighbor[Player::X] = 0;
    _maximumNeighbor[Player::O] = 0;
    _playerCoordinates[Player::X].clear();
    _playerCoordinates[Player::O].clear();
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

void GomokuModel::save(QString filename, IPersistence* persistence)
{
    bool res = persistence->save(filename, this);
}

void GomokuModel::load(QString filename, IPersistence *persistence)
{
    bool res = persistence->load(filename, this);
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

void GomokuModel::mess(Player player)
{
    int maximumNeighbor = _maximumNeighbor[player];
    int numberGenerationCounter =  maximumNeighbor == 3 ? 1 : 2;
    for (int i = 0; i < numberGenerationCounter; ++i)
    {
        int randomNumber = QRandomGenerator::global()->bounded(_playerCoordinates[player].size());
        QPair<int,int> coordinate = _playerCoordinates[player][randomNumber];
        _table[coordinate.first][coordinate.second] = Player::None;
        emit tableChanged(coordinate.first, coordinate.second, Player::None);
        _playerCoordinates[player].removeAt(randomNumber);
    }
}

void GomokuModel::reloadMaxNeighbor(Player player)
{
    int maximum = 0;
    for (auto coordinate: _playerCoordinates[player])
    {
        int neighboring = maxNeighboring(coordinate.first, coordinate.second);
        maximum = neighboring > maximum ? neighboring : maximum;
    }
    _maximumNeighbor[player] = maximum;
}
