#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

enum class Player{
    None, X, O
};

QString playerToString(Player player);
Player stringToPlayer(QString player);

#endif // PLAYER_H
