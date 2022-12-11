#include "filemanager.h"

#include <QFile>
#include <QTextStream>

Filemanager::Filemanager(QObject *parent)
    : IPersistence{parent}
{

}

bool Filemanager::save(QString filename, const GomokuModel* model)
{
    QFile file(filename);
    if (!file.open(QFile::WriteOnly))
        return false;

    QTextStream stream(&file);
    stream << model->getSize() << "\n";
    stream << playerToString(model->getCurrentPlayer()) << "\n";
    QVector<QVector<Player>> table = model->getTable();
    for (int i = 0; i < model->getSize(); ++i)
    {
        QString str;
        for (int j = 0; j < model->getSize(); ++j)
        {
            str.append(playerToString(table[i][j]));
            if (j != model->getSize()-1)
                str.append(';');
        }
        stream << str << "\n";
    }
    return true;
}

bool Filemanager::load(QString filename, GomokuModel* model)
{
    QFile file(filename);
    if (!file.open(QFile::ReadOnly))
        return false;

    QTextStream stream(&file);
    int size = stream.readLine().toInt();
    if (std::find(possibleSizes.begin(), possibleSizes.end(), size) == possibleSizes.end())
        return false;
    Player current = stringToPlayer(stream.readLine());
    QVector<QVector<Player>> table;
    for (int i = 0; i < size; ++i)
    {
        QVector<Player> row;
        QString line = stream.readLine();
        auto splitted = line.split(';');
        for (auto word: splitted)
        {
            row.append(stringToPlayer(word));
        }
        table.append(row);
    }
    if (table.size() != size)
        return false;
    for (int i = 0; i < table.size(); ++i)
    {
        if (table[i].size() != size)
            return false;
    }
    model->setSize(size);
    model->setTable(table);
    model->setCurrentPlayer(current);
    return true;
}
