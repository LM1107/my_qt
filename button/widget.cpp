#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    pb = new QPushButton("OK");
    pbb = new QPushButton("cancle");

    pbb->setFixedSize(50,50);
#if 0
    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addWidget(pb);
    hbox->addWidget(pbb);
#else
    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addStretch();
    hbox->addWidget(pbb);
    hbox->addStretch();

    //垂直布局
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(pb);
    //vbox->addWidget(pbb);
    vbox->addLayout(hbox);
#endif
    this->setLayout(vbox);

    /* 信号与槽的工作机制，当信号与槽进行关联后，只要产生这个信息，就会自动调用槽函数
     *
     * 关联信号与槽connect
     *       谁产生了信号，产生了生么信号，谁去处理信号，槽函数
     */
    connect(pb,SIGNAL(clicked(bool)),this,SLOT(show_clicked_OK()));
    connect(pbb,SIGNAL(clicked(bool)),this,SLOT(close()));
}

Widget::~Widget()
{

}

void Widget::show_clicked_OK()
{
    qDebug()<<"OK has been clicked";
}

/*
void Widget::show_clicked_CAN()
{
    qDebug()<<"CANCLE has been clicked";
}
*/
