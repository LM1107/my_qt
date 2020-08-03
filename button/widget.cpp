#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    pb = new QPushButton("OK");
    pbb = new QPushButton("cancle");

#if 0
    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addWidget(pb);
    hbox->addWidget(pbb);
#else
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(pb);
    vbox->addWidget(pbb);
#endif
    this->setLayout(vbox);
}

Widget::~Widget()
{

}
