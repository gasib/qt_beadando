#include "xowidget.h"

#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>
#include <QPen>

XOWidget::XOWidget(QWidget *parent)
    : QWidget{parent}
{
    _type = Player::None;
}

void XOWidget::setType(Player type)
{
    _type = type;
    update();
}

void XOWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    int penSize = 2;
    painter.setPen(QPen(Qt::black, penSize));
    QRectF rectangle(penSize,penSize,width() - penSize - 1, height() - penSize - 1);
    if (_type == Player::O)
    {
        painter.drawEllipse(rectangle);
    }
    else if (_type == Player::X)
    {
        painter.drawLine(0,0,width(), height());
        painter.drawLine(width(), 0, 0, height());
    }

    painter.setPen(QPen(Qt::black, 1));
    painter.drawRect(QRectF(0,0,width()-1, height()-1));
}

void XOWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        emit clicked();
    }
}
