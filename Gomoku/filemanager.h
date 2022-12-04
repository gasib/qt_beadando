#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "gomokumodel.h"
#include "player.h"

#include <QObject>
#include <QVector>

class IPersistence : public QObject
{
    Q_OBJECT

public:

    explicit IPersistence(QObject* parent = nullptr);

    virtual void save(QString filename, GomokuModel& model) = 0;
    virtual QVector<QVector<Player>> load(QString filename) = 0;
};

class Filemanager : public IPersistence
{
    Q_OBJECT
public:
    explicit Filemanager(QObject *parent = nullptr);

    virtual void save(QString filename, GomokuModel& model) override;
    virtual QVector<QVector<Player>> load(QString filename) override;

signals:

};

#endif // FILEMANAGER_H
