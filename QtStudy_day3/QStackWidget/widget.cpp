#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setFixedSize(700,500);
    l1 = new QLabel;
    l1->setFixedSize(680,480);
    l1->setScaledContents(true);
    l1->setPixmap(QPixmap(":/pic/1.jpg"));

    l2 = new QLabel;
    l2->setFixedSize(640,480);
    l2->setScaledContents(true);
    l2->setPixmap(QPixmap(":/pic/2.jpg"));

    l3 = new QLabel;
    l3->setFixedSize(640,480);
    l3->setScaledContents(true);
    l3->setPixmap(QPixmap(":/pic/3.jpg"));

    cbb = new QComboBox;
    cbb->addItem(QIcon(":/pic/1.jpg"),"1.jpg");
    cbb->addItem(QIcon(":/pic/2.jpg"),"2.jpg");
    cbb->addItem(QIcon(":/pic/3.jpg"),"3.jpg");

    sw = new QStackedWidget;
    sw->addWidget(l1);
    sw->addWidget(l2);
    sw->addWidget(l3);

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addStretch();
    hbox->addWidget(cbb);
    hbox->addStretch();

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(sw);
    vbox->addLayout(hbox);
    setLayout(vbox);

    connect(cbb,SIGNAL(currentIndexChanged(int)),this,SLOT(setStackWidget()));

}

Widget::~Widget()
{

}

void Widget::setStackWidget()
{
    int count = cbb->currentIndex();
    sw->setCurrentIndex(count);
}
