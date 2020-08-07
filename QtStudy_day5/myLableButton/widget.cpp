#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    l = new myLabel("showPic");
    l->setFixedSize(640,480);
    l->setAlignment(Qt::AlignHCenter);
    l->setScaledContents(true);
    le = new QLineEdit;

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(le);
    vbox->addWidget(l);
    setLayout(vbox);

    connect(l,SIGNAL(clicked(bool)),this,SLOT(showPic()));
    connect(l,SIGNAL(release(bool)),this,SLOT(changePic()));

}

Widget::~Widget()
{

}

void Widget::showPic()
{
    l->setPixmap(QPixmap(":/pic/1.jpg"));
}

void Widget::changePic()
{
    l->setPixmap(QPixmap(":/pic/2.jpg"));
}
