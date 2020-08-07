#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

Widget::~Widget()
{

}

void Widget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "mouse pressed!";

    if(event->button() == Qt::LeftButton)
        qDebug() << "Left Button pressed!";
    if(event->button() == Qt::RightButton)
        qDebug() << "Right button pressed!";
    else
        qDebug() << "Other button pressed!";

    qDebug() << event->pos() << event->x() << event->y();
    qDebug() << event->globalPos() << event->globalX() << event->globalY();

}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug()<<"mouse released";
}

void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug()<<"mouse double clicked";
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug()<< event->pos()<<event->x()<<event->y();
}
