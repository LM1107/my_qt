#include "mywidget.h"

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    QFont font("TIME",50,QFont::Bold);
    le = new QLineEdit();
    le->setFont(font);
    le->setText(QString::number(0));
    le->setAlignment(Qt::AlignLeft);
    pb1 = new QPushButton("+");
    pb2 = new QPushButton("-");
    pb1->setFont(font);
    pb2->setFont(font);

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addWidget(pb1);
    hbox->addWidget(pb2);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(le);
    vbox->addLayout(hbox);

    this->setLayout(vbox);

    num=0;

    connect(pb1,SIGNAL(clicked(bool)),this,SLOT(my_add()));
    connect(pb2,SIGNAL(clicked(bool)),this,SLOT(my_minus()));

}

myWidget::~myWidget()
{

}

void myWidget::my_add()
{
#if 1
    QString str = le->text();
    le->setText(QString::number(str.toInt()+1));
#else
    num++;
    le->setText(QString::number(num));
#endif
}

void myWidget::my_minus()
{
#if 1
    QString str = le->text();
    le->setText(QString::number(str.toInt()-1));
#else
    num--;
    le->setText(QString::number(num));
#endif
}
