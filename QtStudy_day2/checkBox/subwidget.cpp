#include "subwidget.h"

subWidget::subWidget(QWidget *widget,QWidget *parent) : QWidget(parent)
{
    w = widget;

    pb1 = new QPushButton("return");
    pb2 = new QPushButton("Close");

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addWidget(pb1);
    hbox->addWidget(pb2);
    setLayout(hbox);

    connect(pb1,SIGNAL(clicked(bool)),this,SLOT(returnWidget()));
    connect(pb2,SIGNAL(clicked(bool)),this,SLOT(close()));

}

void subWidget::returnWidget()
{
    this->close();
    w->show();
}
