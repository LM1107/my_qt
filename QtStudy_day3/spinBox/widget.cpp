#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QFont font("Times",30,QFont::Bold);
    le = new QLineEdit;
    le->setText("0");
    le->setFont(font);

    sb = new QSpinBox;
    sb->setFont(font);
    sb->setPrefix("距离：");   //设置前缀
    sb->setSuffix("米");     //设置后缀
    sb->setRange(-10,10);   //设置范围
    sb->setValue(5);        //设置值
    sb->setSingleStep(2);   //设置步长

    dsb = new QDoubleSpinBox;
    dsb->setValue(0);
    dsb->setFont(font);
    dsb->setPrefix("价格：");
    dsb->setSuffix("元");
    dsb->setRange(-10,10);
    dsb->setSingleStep(0.5);
    dsb->setDecimals(2);    //设置精度

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(le);
    vbox->addWidget(sb);
    vbox->addWidget(dsb);
    setLayout(vbox);

    connect(sb,SIGNAL(valueChanged(int)),this,SLOT(setVal(int)));
    connect(dsb,SIGNAL(valueChanged(double)),this,SLOT(setDVal(double)));

}

Widget::~Widget()
{

}

void Widget::setVal(int num)
{
    le->setText(QString::number(num));
    dsb->setValue(num);
}

void Widget::setDVal(double num)
{
    le->setText(QString::number(num));
    sb->setValue(num);
}
