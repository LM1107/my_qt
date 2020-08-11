#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    flag = 0;
    te = new QTimeEdit(QTime::currentTime(),this);
    te->setDisplayFormat("hh:mm:ss");

    t = new QTimer;
    t->start(1000);
    connect(t,SIGNAL(timeout()),this,SLOT(showTime()));

    st = new subThread;
    st->start();
}

Widget::~Widget()
{

}

void Widget::showTime()
{
    QTime time = QTime::currentTime();
    te->setTime(time);
//    if(flag == 0)
//    {
//        while(1){
//            qDebug() << "nihao!";
//            QThread::sleep(1);
//        }
//    }
//    flag = 1;
}
