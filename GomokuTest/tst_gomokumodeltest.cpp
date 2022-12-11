#include <QtTest>

// add necessary includes here
#include "../Gomoku/gomokumodel.h"
#include "../Gomoku/player.h"
#include "ipersistencemock.h"

class GomokuModelTest : public QObject
{
    Q_OBJECT

private slots:
    void test_tableInitialization();
    void test_setCurrentPlayer();
    void test_setTable();
    void test_checkTable_data();
    void test_checkTable();
    void test_mess_data();
    void test_mess();
    void test_save();
    void test_load();
};

void GomokuModelTest::test_tableInitialization()
{
    GomokuModel gm(nullptr);
    int tableSize = 6;
    QSignalSpy initSpy(&gm, &GomokuModel::tableInitialized);

    gm.initTable(tableSize);
    const auto table = gm.getTable();
    QCOMPARE(gm.getSize(),tableSize);
    QCOMPARE(table.size(),tableSize);
    QCOMPARE(table[0].size(),tableSize);
    QCOMPARE(gm.getCurrentPlayer(),Player::X);
    for (int i = 0; i < tableSize; ++i)
    {
        for (int j = 0; j < tableSize; ++j)
        {
            QCOMPARE(table[i][j],Player::None);
        }
    }

    QCOMPARE(initSpy.count(), 1);
}

void GomokuModelTest::test_setCurrentPlayer()
{
    Player playerToSet = Player::O;
    GomokuModel gm;
    // It represent a valid state where the function will be used
    gm.initTable(6);
    QSignalSpy spy(&gm, &GomokuModel::currentPlayerChanged);

    gm.setCurrentPlayer(playerToSet);
    QCOMPARE(gm.getCurrentPlayer(), playerToSet);
    QCOMPARE(spy.count(), 1);
}

void GomokuModelTest::test_setTable()
{
    const QVector<QVector<Player>> tableToSet = {
        {Player::O, Player::None},
        {Player::None, Player::X}
    };
    GomokuModel gm;
    QSignalSpy spy(&gm, &GomokuModel::tableInitialized);

    gm.setTable(tableToSet);
    QCOMPARE(gm.getTable(), tableToSet);
    QCOMPARE(spy.count(), 1);
}

void GomokuModelTest::test_checkTable_data()
{
    // table, current player, coordinatex, coordinatey, what should it be after click
    QVector<QVector<Player>> table = {
        {Player::O, Player::None},
        {Player::None, Player::X}
    };

    QTest::addColumn<QVector<QVector<Player>>>("table");
    QTest::addColumn<Player>("currentPlayer");
    QTest::addColumn<int>("x");
    QTest::addColumn<int>("y");
    QTest::addColumn<Player>("playerAfterCheck");

    QTest::addRow("Player X on None") << table << Player::X << 0 << 1 << Player::X;
    QTest::addRow("Player O on None") << table << Player::O << 0 << 1 << Player::O;
    QTest::addRow("Player X on O") << table << Player::X << 0 << 0 << Player::O;
    QTest::addRow("Player O on X") << table << Player::O << 1 << 1 << Player::X;
}

void GomokuModelTest::test_checkTable()
{
    QFETCH(QVector<QVector<Player>>, table);
    QFETCH(Player, currentPlayer);
    QFETCH(int, x);
    QFETCH(int, y);
    QFETCH(Player, playerAfterCheck);

    GomokuModel gm;
    gm.setTable(table);
    gm.setCurrentPlayer(currentPlayer);
    gm.checkTable(x,y);
    const auto newTable = gm.getTable();
    QCOMPARE(newTable[x][y], playerAfterCheck);
}

void GomokuModelTest::test_mess_data()
{
    QTest::addColumn<QVector<QVector<Player>>>("table");
    QTest::addColumn<Player>("currentPlayer");
    QTest::addColumn<int>("x");
    QTest::addColumn<int>("y");
    QTest::addColumn<int>("expectedPlayerAfterCheck");

    QVector<QVector<Player>> table1 = {
        {Player::X, Player::X, Player::None, Player::None, Player::None},
        {Player::None, Player::None, Player::None, Player::None, Player::None},
        {Player::None, Player::None, Player::None, Player::None, Player::None},
        {Player::None, Player::None, Player::None, Player::None, Player::None},
        {Player::None, Player::None, Player::None, Player::None, Player::None}
    };

    QVector<QVector<Player>> table2 = {
        {Player::X, Player::X, Player::X, Player::None, Player::None},
        {Player::None, Player::None, Player::None, Player::None, Player::None},
        {Player::None, Player::None, Player::None, Player::None, Player::None},
        {Player::None, Player::None, Player::None, Player::None, Player::None},
        {Player::None, Player::None, Player::None, Player::None, Player::None}
    };

    QVector<QVector<Player>> table3 = {
        {Player::X, Player::X, Player::X, Player::X, Player::None},
        {Player::None, Player::None, Player::None, Player::None, Player::None},
        {Player::None, Player::None, Player::None, Player::None, Player::None},
        {Player::None, Player::None, Player::None, Player::None, Player::None},
        {Player::None, Player::None, Player::None, Player::None, Player::None}
    };

    QTest::addRow("Third player in a row; removes only one") << table1 << Player::X << 0 << 2 << 2;
    QTest::addRow("Fourth player in a row; removes two") << table2 << Player::X << 0 << 3 << 2;
    QTest::addRow("Fifth in a row; removes none") << table3 << Player::X << 0 << 4 << 5;
}

void GomokuModelTest::test_mess()
{
    QFETCH(QVector<QVector<Player>>, table);
    QFETCH(Player, currentPlayer);
    QFETCH(int, x);
    QFETCH(int, y);
    QFETCH(int, expectedPlayerAfterCheck);
    GomokuModel gm;
    gm.setTable(table);
    gm.setCurrentPlayer(currentPlayer);
    gm.checkTable(x,y);
    int counter = 0;
    const auto newTable = gm.getTable();
    for (const auto& row: newTable)
    {
        for (const auto item: row)
        {
            if (item == currentPlayer)
                counter++;
        }
    }
    QCOMPARE(counter, expectedPlayerAfterCheck);
}

void GomokuModelTest::test_save()
{
    IPersistenceMock mock;
    GomokuModel gm;
    QSignalSpy spy(&mock, &IPersistenceMock::saved);
    gm.save("test", &mock);
    QCOMPARE(spy.count(), 1);
}

void GomokuModelTest::test_load()
{
    int testSize = 2;
    Player testPlayer = Player::O;
    QVector<QVector<Player>> testTable = {
        { Player::X, Player::O },
        { Player::None, Player::X }
    };
    IPersistenceMock mock(testSize, testTable, testPlayer);
    GomokuModel gm;
    QSignalSpy spy(&mock, &IPersistenceMock::loaded);
    gm.load("test", &mock);
    QCOMPARE(spy.count(), 1);
    QCOMPARE(gm.getSize(), testSize);
    QCOMPARE(gm.getCurrentPlayer(), testPlayer);
    QCOMPARE(gm.getTable(), testTable);
}

QTEST_APPLESS_MAIN(GomokuModelTest)

#include "tst_gomokumodeltest.moc"
