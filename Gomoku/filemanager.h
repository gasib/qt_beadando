#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "ipersistence.h"
#include "gomokumodel.h"

#include <QObject>
#include <QVector>

class Filemanager : public IPersistence
{
    Q_OBJECT
public:
    explicit Filemanager(QObject *parent = nullptr);

    virtual bool save(QString filename, GomokuModel* model) override;
    virtual bool load(QString filename, GomokuModel* model) override;

signals:

};

#endif // FILEMANAGER_H
