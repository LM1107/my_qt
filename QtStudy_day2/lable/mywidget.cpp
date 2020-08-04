#include "mywidget.h"

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    l = new QLabel("text",this);
    l->setFixedSize(1920,1080);
    l->setPixmap(QPixmap(":/pic/wallhaven-yj135g.jpg"));
    l->setScaledContents(true);
}

myWidget::~myWidget()
{

}
