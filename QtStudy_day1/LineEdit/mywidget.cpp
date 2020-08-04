#include "mywidget.h"

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    QFont font("Times",50,QFont::Bold);  //设置字体
    le = new QLineEdit();
    le->setFont(font);      //设置字体
    le->setAlignment(Qt::AlignRight);   //设置对齐
    pb = new QPushButton("show");
    pb->setFont(font);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(le);
    vbox->addWidget(pb);
    setLayout(vbox);

    connect(pb,SIGNAL(clicked(bool)),this,SLOT(show_le()));

}

myWidget::~myWidget()
{

}

void myWidget::show_le()
{
    QString str = le->text();   //获取行编辑器的内容
    qDebug() << str;
//    le->setText("hello");     //设置行编辑器内容
    le->setText(QString::number(0));
}

