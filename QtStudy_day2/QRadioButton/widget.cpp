#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QFont font("Times",30,QFont::Bold);
    l = new QLabel("第一题:1+1=?");
    l->setFont(font);

    rp1 = new QRadioButton("0");
    rp2 = new QRadioButton("1");
    rp3 = new QRadioButton("2");
    rp4 = new QRadioButton("3");

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(l);
    vbox->addWidget(rp1);
    vbox->addWidget(rp2);
    vbox->addWidget(rp3);
    vbox->addWidget(rp4);

    gbox1 = new QGroupBox("第一题");
    gbox1->setLayout(vbox);

    connect(rp1,SIGNAL(clicked(bool)),this,SLOT(show_radioButton()));
    connect(rp2,SIGNAL(clicked(bool)),this,SLOT(show_radioButton()));
    connect(rp3,SIGNAL(clicked(bool)),this,SLOT(show_radioButton()));
    connect(rp4,SIGNAL(clicked(bool)),this,SLOT(show_radioButton()));

    l2 = new QLabel("第二题:下面那种水果是红色的");
    QStringList list={"Apple","Orange","Banana","Watermelon"};
    l2->setFont(font);
    for(int i=0;i<4;i++)
    {
        rb[i] = new QRadioButton(list.at(i));
    }

    QVBoxLayout *vbox1 = new QVBoxLayout;
    vbox1->addWidget(l2);
    for(int i=0;i<4;i++)
    {
        vbox1->addWidget(rb[i]);
    }

    gbox2 = new QGroupBox("第二题");
    gbox2->setLayout(vbox1);

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addWidget(gbox1);
    hbox->addWidget(gbox2);

    setLayout(hbox);

    for(int i=0;i<4;i++)
        connect(rb[i],SIGNAL(clicked(bool)),this,SLOT(show_radioButton()));

}

Widget::~Widget()
{

}

void Widget::show_radioButton()
{
    QRadioButton *rbb = static_cast<QRadioButton*>(sender());
    qDebug() << rbb->text();
    if(rp3->isChecked())
        qDebug() << "1+1=2";
    if(rb[0]->isChecked())
        qDebug() << "Apple是红色的";
}
