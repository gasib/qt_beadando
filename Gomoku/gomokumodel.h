#ifndef GOMOKUMODEL_H
#define GOMOKUMODEL_H

#include "ipersistence.h"
#include "player.h"

#include <QObject>
#include <QVector>
#include <QMap>

class GomokuModel : public QObject
{
    Q_OBJECT
public:
    explicit GomokuModel(QObject *parent = nullptr);
    ~GomokuModel();

    void checkTable(int x, int y);
    int getSize() const { return _tableSize; };
    void setSize(int newSize) { _tableSize = newSize; };
    Player getCurrentPlayer() const { return _currentPlayer; };
    void setCurrentPlayer(Player player);
    QVector<QVector<Player>> getTable() const { return _table; };
    void setTable(QVector<QVector<Player>> newTable);
    void initTable(int size);
    void save(QString filename, IPersistence* persistence);
    void load(QString filename, IPersistence* persistence);

signals:

    void tableInitialized();
    void tableChanged(int x, int y, Player player);
    void invalidPosition(int x, int y);
    void gameWon(Player player);
    void gameOver();
    void currentPlayerChanged();
    void fileError();

private:

    bool canBeChecked(int x, int y);
    // Must be call before changing player
    int maxNeighboring(int x, int y);
    int checkInDirection(int x, int y, int dirx, int diry, int current, Player player);
    bool isAllChecked();
    void mess(Player player);
    void reloadMaxNeighbor(Player player);

private:

    QVector<QVector<Player>> _table;
    QMap<Player, int> _maximumNeighbor;
    QMap<Player, QVector<QPair<int,int>>> _playerCoordinates;
    Player _currentPlayer;
    int _tableSize;
};

#endif // GOMOKUMODEL_H
