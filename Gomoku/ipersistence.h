#ifndef IPERSISTENCE_H
#define IPERSISTENCE_H

#include <QObject>

class GomokuModel;

class IPersistence : public QObject
{
    Q_OBJECT
public:
    explicit IPersistence(QObject *parent = nullptr);

    virtual bool save(QString filename, const GomokuModel* model) = 0;
    virtual bool load(QString filename, GomokuModel* model) = 0;

signals:

protected:

    const static inline QVector<int> possibleSizes = {6, 10, 14};

};

#endif // IPERSISTENCE_H
