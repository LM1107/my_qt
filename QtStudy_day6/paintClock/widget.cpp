#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    pixmap = new QPixmap(640,480);
    pixmap->fill();

    t = new QTimer(this);
    connect(t,SIGNAL(timeout()),this,SLOT(update()));
        t->start(1000);
}

Widget::~Widget()
{

}

void Widget::paintEvent(QPaintEvent *event)
{
    QTime time = QTime::currentTime();

    QPainter p(this);

    p.setRenderHint(QPainter::Antialiasing);

    QPen pen(Qt::black);
    pen.setWidth(4);
    p.setPen(pen);
    p.drawEllipse(QPoint(250,250),130,130);
    p.translate(250,250);
    p.drawPoint(0,0);

    p.save();
    p.rotate(6.0*time.second());
    p.drawLine(QPoint(0,-7),QPoint(0,-100));
    p.restore();

    p.save();
    p.rotate(6.0*(time.minute()+time.second()/60.0));
    p.drawLine(QPoint(0,-7),QPoint(0,-90));
    p.restore();

    p.save();
    p.rotate(30.0*(time.hour()+time.minute()/60.0));
    p.drawLine(QPoint(0,-7),QPoint(0,-80));
    p.restore();

    for(int i=0;i<12;i++)
    {
        if(i%3==0)
        {
            QPen thickPen(Qt::black);
            thickPen.setWidth(7);
            p.setPen(thickPen);
            p.drawLine(QPoint(0,105),QPoint(0,110));
        }else {
            p.setPen(pen);
            p.drawLine(QPoint(0,105),QPoint(0,110));
        }
        p.rotate(30.0);
    }
}
