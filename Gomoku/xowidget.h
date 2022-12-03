#ifndef XOWIDGET_H
#define XOWIDGET_H

#include "player.h"

#include <QWidget>

class XOWidget : public QWidget
{
    Q_OBJECT
public:
    explicit XOWidget(QWidget *parent = nullptr);

    void setType(Player type);

signals:

    void clicked();

protected:

    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;

private:

    Player _type;

};

#endif // XOWIDGET_H
