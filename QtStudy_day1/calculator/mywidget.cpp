#include "mywidget.h"

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    num1 = -1;
    num2 = -1;
    sum = -1;
    flag = 0;
    flagp = 0;

    QFont font("Times",30,QFont::Bold);
    le = new QLineEdit();
    le->setFont(font);
    le->setAlignment(Qt::AlignRight);
    le->setText(0);

    for(int i = 0;i<10;i++)
    {
        pb_num[i] = new QPushButton(QString::number(i));
        pb_num[i]->setFixedSize(50,50);
    }

    QStringList list = {"+","-","*","/","="};
    for(int i=0;i<5;i++)
    {
        pb_expr[i] = new QPushButton(list.at(i));
        pb_expr[i]->setFixedSize(50,50);
    }

    pbpot = new QPushButton(".");
    pbclr = new QPushButton("AC");
    pbdel = new QPushButton("del");

    pbpot->setFixedSize(50,50);
    pbclr->setFixedSize(50,50);
    pbdel->setFixedSize(50,50);

    QGridLayout *gbox = new QGridLayout;
    gbox->addWidget(le,  0, 0, 1, 4);
    gbox->addWidget(pb_expr[0], 1, 3, 1, 1); //控件，行，列，占几行，占几列
    gbox->addWidget(pb_expr[1], 2, 3, 1, 1);
    gbox->addWidget(pb_expr[2], 3, 3, 1, 1);
    gbox->addWidget(pb_expr[3], 4, 3, 1, 1);
    gbox->addWidget(pb_expr[4],  5, 3, 1, 1);

    gbox->addWidget(pbclr,1,0, 1, 2);
    gbox->addWidget(pb_num[7], 2, 0, 1, 1);
    gbox->addWidget(pb_num[4], 3, 0, 1, 1);
    gbox->addWidget(pb_num[1], 4, 0, 1, 1);
    gbox->addWidget(pb_num[0], 5, 0, 1, 1.5);

    gbox->addWidget(pb_num[8], 2, 1, 1, 1);
    gbox->addWidget(pb_num[5], 3, 1, 1, 1);
    gbox->addWidget(pb_num[2], 4, 1, 1, 1);
    gbox->addWidget(pbpot,5,2, 1, 1.5);
    gbox->addWidget(pbdel,1,2, 1, 2);

    gbox->addWidget(pb_num[9], 2, 2, 1, 1);
    gbox->addWidget(pb_num[6], 3, 2, 1, 1);
    gbox->addWidget(pb_num[3], 4, 2, 1, 1);

    setLayout(gbox);

    for(int i=0;i<10;i++)
        connect(pb_num[i],SIGNAL(clicked(bool)),this,SLOT(my_counter()));

    connect(pb_expr[0],SIGNAL(clicked(bool)),this,SLOT(my_add()));
    connect(pb_expr[1],SIGNAL(clicked(bool)),this,SLOT(my_minus()));
    connect(pb_expr[2],SIGNAL(clicked(bool)),this,SLOT(my_multiply()));
    connect(pb_expr[3],SIGNAL(clicked(bool)),this,SLOT(my_division()));
    connect(pb_expr[4],SIGNAL(clicked(bool)),this,SLOT(my_equal()));

    connect(pbpot,SIGNAL(clicked(bool)),this,SLOT(point_clicked()));
    connect(pbclr,SIGNAL(clicked(bool)),this,SLOT(my_ac()));
}

myWidget::~myWidget()
{
    temp.clear();
}

void myWidget::my_add()
{
    temp.clear();
    flag = 1;
}

void myWidget::my_minus()
{
    temp.clear();
    flag = 2;
}

void myWidget::my_multiply()
{
    temp.clear();
    flag = 3;
}

void myWidget::my_division()
{
    temp.clear();
    flag = 4;
}

void myWidget::my_counter()
{
    if(flag == 0||flagp == 1)
    {
        if(flagp == 1)
        {
            temp.append(".");
            flagp = 0;
            le->setText(temp);
        }QPushButton *p = static_cast<QPushButton*>(sender());
        QString str = p->text();
        temp = temp+str;
        le->clear();
        le->setText(temp);
        num1 = temp.toDouble();
    }
    else{
        QPushButton *p = static_cast<QPushButton*>(sender());
        QString str = p->text();
        temp = temp+str;
        le->clear();
        le->setText(temp);
        num2 = temp.toDouble();
    }
}

void myWidget::my_equal()
{
    if(flag == 1&&num2!=-1)
    {
        sum = num1+num2;
    }else if(flag == 2&&num2!=-1)
    {
        sum = num1-num2;
    }else if(flag == 3&&num2!=-1)
    {
        sum = num1*num2;
    }else if(flag == 4&&num2!=-1)
    {
        sum = num1/num2;
    }
    le->setText(QString::number(sum));
}

void myWidget::my_ac()
{
    num1 = -1;
    num1 = -1;
    sum = -1;
    flag = 0;
    flagp = 0;
    temp.clear();
    le->setText(0);
}

void myWidget::point_clicked()
{
    flagp = 1;
}

