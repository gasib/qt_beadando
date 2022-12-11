#ifndef IPERSISTENCEMOCK_H
#define IPERSISTENCEMOCK_H

#include "../Gomoku/ipersistence.h"
#include "../Gomoku/player.h"

class IPersistenceMock: public IPersistence
{
    Q_OBJECT
public:
    IPersistenceMock();
    IPersistenceMock(const int size, const QVector<QVector<Player>>& table, const Player current);

    void loadTestData(const int size, const QVector<QVector<Player>>& table, const Player current);
    bool save(QString fileName, const GomokuModel* model) override;
    bool load(QString fileName, GomokuModel* model) override;

signals:

    void saved();
    void loaded();

private:

    int _size;
    QVector<QVector<Player>> _table;
    Player _current;

};

#endif // IPERSISTENCEMOCK_H
