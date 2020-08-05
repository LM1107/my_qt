#include "mywidget.h"

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    te = new QTimeEdit;
    te->setDisplayFormat("hh:mm:ss");   //设置显示格式
    QTime t = QTime::currentTime();     //获取当前时间
    te->setTime(t);

    dte = new QDateTimeEdit;
    dte->setDisplayFormat("yyyy-MM-dd hh:mm:ss A ddd"); //设置显示格式
    QDateTime dt = QDateTime::currentDateTime();
    dte->setDateTime(dt);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(te);
    vbox->addWidget(dte);
    setLayout(vbox);

    timer = new QTimer;
    timer->start(1000);     //启动定时器，单位毫秒
    connect(timer,SIGNAL(timeout()),this,SLOT(changeTime()));

/*
 * 会导致程序未响应
    while (1) {
        QThread::sleep(1);
    }
*/
}

myWidget::~myWidget()
{

}

void myWidget::changeTime()
{
    QTime t = QTime::currentTime();
    te->setTime(t);
    QDateTime dt = QDateTime::currentDateTime();
    dte->setDateTime(dt);
}
