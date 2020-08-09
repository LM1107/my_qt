#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    pixmap = new QPixmap(640,480);
    pixmap->fill();     //用白色填充图片
    setMouseTracking(true);
}

Widget::~Widget()
{

}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter pp(pixmap);
    QPen pen(Qt::red);
    pen.setWidth(5);
    pp.setPen(pen);

    pp.drawPoint(point);

    QPainter p(this);
    p.drawPixmap(0,0,*pixmap);
    /*
    QPainter p(this);
    QPen pen(Qt::red);
    pen.setWidth(5);
    p.setPen(pen);
    p.drawPoint(100,100);
    p.drawPoint(point);
    */
}
/*
void Widget::mousePressEvent(QMouseEvent *event)
{
    point = event->pos();
    update();
}
*/
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    setMouseTracking(true);
    point = event->pos();
    update();
}
