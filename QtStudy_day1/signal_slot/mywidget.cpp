#include "mywidget.h"

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    pb1 = new QPushButton("OK");
    pb2 = new QPushButton("CANCLE");

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addWidget(pb1);
    hbox->addWidget(pb2);
    setLayout(hbox);

    /*
     *  信号与槽机制：
     *  1）一对一：一个信号对应一个槽函数；
     *  2）一对多：一个信号可以对应多个槽函数，当信号产生时所对应的槽函数都会被调用，调用顺序不定
     *  3）多对一：多个信号可以对应同一个槽函数，这些信号中任意一个产生，槽函数都会调用一次
     *  4）信号1可以和信号2关联，当信号1产生信号时信号2自动产生，但是信号2产生时信号1不会产生
     *  5）槽函数的参数：
     *      槽函数是由信号产生的，系统自动调用的，槽函数被调用时，是由信号来传参，所以槽函数的参数个数是<=信号的参数
     *      槽函数如果有参，信号的参数按槽函数的参数个数一次传递给槽函数的参数
     *  6）解除关系：
     *      disconnect，用法与connect完全一致
     */

    connect(pb1,SIGNAL(clicked(bool)),this,SLOT(OK_CLICKED()));
    //connect(pb2,SIGNAL(clicked(bool)),this,SLOT(CAN_CLICKED()));
    //connect(pb1,SIGNAL(clicked(bool)),this,SLOT(CAN_CLICKED()));
    //connect(pb1,SIGNAL(clicked(bool)),pb2,SIGNAL(clicked(bool)));

}

myWidget::~myWidget()
{

}

void myWidget::OK_CLICKED()
{
    qDebug() << "OK CLICKED";
    disconnect(pb1,SIGNAL(clicked(bool)),this,SLOT(OK_CLICKED()));
}

void myWidget::CAN_CLICKED()
{
    qDebug() << "CANCLE CLICKED";
}
