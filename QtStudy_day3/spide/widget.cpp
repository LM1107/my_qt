#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    le = new QLineEdit;

    sb = new QScrollBar;
    sb->setOrientation(Qt::Horizontal);
    sb->setValue(0);
    sb->setRange(0,100);

    sd = new QSlider;
    sd->setOrientation(Qt::Horizontal); //设置水平放置
    sd->setValue(0);
    sd->setRange(0,100);

    pgb = new QProgressBar;
    pgb->setRange(0,100);
    pgb->setValue(50);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(le);
    vbox->addWidget(sd);
    vbox->addWidget(sb);
    vbox->addWidget(pgb);
    setLayout(vbox);

    connect(sd,SIGNAL(valueChanged(int)),this,SLOT(setValues()));
    connect(sb,SIGNAL(valueChanged(int)),sd,SLOT(setValue(int)));
    connect(sb,SIGNAL(valueChanged(int)),le,SLOT(setValue(int)));

}

Widget::~Widget()
{

}

void Widget::setValues()
{
    int value = sd->value();
    le->setText(QString::number(value));
    sb->setValue(value);
    pgb->setValue(value);

}
