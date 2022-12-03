#ifndef GOMOKUMODEL_H
#define GOMOKUMODEL_H

#include "player.h"

#include <QObject>
#include <QVector>

enum class Direction {
    Top, TopRight, Right, BottomRight, Bottom, BottomLeft, Left, TopLeft
};

class GomokuModel : public QObject
{
    Q_OBJECT
public:
    explicit GomokuModel(QObject *parent = nullptr);

    void checkTable(int x, int y);
    int getSize() const;
    void initTable(int size);

signals:

    void tableInitialized();
    void tableChanged(int x, int y, Player player);
    void invalidPosition(int x, int y);
    void gameWon(Player player);
    void gameOver();

private:

    bool canBeChecked(int x, int y);
    // Must be call before changing player
    int maxNeighboring(int x, int y);
    int checkInDirection(int x, int y, int dirx, int diry, int current, Player player);
    bool isAllChecked();

private:

    QVector<QVector<Player>> _table;
    Player _currentPlayer;
    int _tableSize;

    int _maxNeighborPlayerX;
    int _maxNeighborPlayerO;
};

#endif // GOMOKUMODEL_H
