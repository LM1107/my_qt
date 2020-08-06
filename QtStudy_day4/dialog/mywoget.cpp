#include "mywoget.h"

myWoget::myWoget(QWidget *parent) : QWidget(parent)
{
    pb1=new QPushButton("OK");
    pb2=new QPushButton("Cancle");

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addWidget(pb1);
    hbox->addWidget(pb2);
    setLayout(hbox);

    connect(pb1,SIGNAL(clicked(bool)),this,SLOT(okClicked()));
    connect(pb2,SIGNAL(clicked(bool)),this,SLOT(cancleClicked()));

}

void myWoget::okClicked()
{
    qDebug() << "ok is clicked";
}

void myWoget::cancleClicked()
{
    qDebug() << "cancle is clicked";
}
