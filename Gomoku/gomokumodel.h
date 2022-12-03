#ifndef GOMOKUMODEL_H
#define GOMOKUMODEL_H

#include <QObject>

class GomokuModel : public QObject
{
    Q_OBJECT
public:
    explicit GomokuModel(QObject *parent = nullptr);

signals:

};

#endif // GOMOKUMODEL_H
