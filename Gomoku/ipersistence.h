#ifndef IPERSISTENCE_H
#define IPERSISTENCE_H

#include <QObject>

class GomokuModel;

class IPersistence : public QObject
{
    Q_OBJECT
public:
    explicit IPersistence(QObject *parent = nullptr);

    virtual bool save(QString filename, GomokuModel* model) = 0;
    virtual bool load(QString filename, GomokuModel* model) = 0;

signals:

};

#endif // IPERSISTENCE_H
