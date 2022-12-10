#include "player.h"

QString playerToString(Player player)
{
    switch (player)
    {
        case Player::None:
            return "None";
        case Player::X:
            return "X";
        case Player::O:
            return "O";
    }
}

Player stringToPlayer(QString player)
{
    if (player == "X")
        return Player::X;
    else if (player == "O")
        return Player::O;

    return Player::None;
}
