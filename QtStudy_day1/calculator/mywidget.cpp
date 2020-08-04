#include "mywidget.h"

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    num1 = -1;
    num2 = -1;
    sum = -1;
    flag = 0;
    temp = 0;

    QFont font("Times",50,QFont::Bold);
    le = new QLineEdit();
    le->setFont(font);
    le->setAlignment(Qt::AlignRight);
    le->setText(0);

    pba = new QPushButton("+");
    pbb = new QPushButton("-");
    pbc = new QPushButton("*");
    pbd = new QPushButton("/");
    pb = new QPushButton("=");

    pb0 = new QPushButton("0");
    pb1 = new QPushButton("1");
    pb2 = new QPushButton("2");
    pb3 = new QPushButton("3");
    pb4 = new QPushButton("4");
    pb5 = new QPushButton("5");
    pb6 = new QPushButton("6");
    pb7 = new QPushButton("7");
    pb8 = new QPushButton("8");
    pb9 = new QPushButton("9");

    pbpot = new QPushButton(".");
    pbclr = new QPushButton("AC");
    pbdel = new QPushButton("del");

    pba->setFixedSize(50,50);
    pbb->setFixedSize(50,50);
    pbc->setFixedSize(50,50);
    pbd->setFixedSize(50,50);
    pb->setFixedSize(50,50);

    pb0->setFixedSize(50,50);
    pb1->setFixedSize(50,50);
    pb2->setFixedSize(50,50);
    pb3->setFixedSize(50,50);
    pb4->setFixedSize(50,50);
    pb5->setFixedSize(50,50);
    pb6->setFixedSize(50,50);
    pb7->setFixedSize(50,50);
    pb8->setFixedSize(50,50);
    pb9->setFixedSize(50,50);

    pbpot->setFixedSize(50,50);
    pbclr->setFixedSize(50,50);
    pbdel->setFixedSize(50,50);

    QGridLayout *gbox = new QGridLayout;
    gbox->addWidget(le,  0, 0, 1, 4);
    gbox->addWidget(pba, 1, 3, 1, 1); //控件，行，列，占几行，占几列
    gbox->addWidget(pbb, 2, 3, 1, 1);
    gbox->addWidget(pbc, 3, 3, 1, 1);
    gbox->addWidget(pbd, 4, 3, 1, 1);
    gbox->addWidget(pb,  5, 3, 1, 1);

    gbox->addWidget(pbclr,1,0, 1, 2);
    gbox->addWidget(pb7, 2, 0, 1, 1);
    gbox->addWidget(pb4, 3, 0, 1, 1);
    gbox->addWidget(pb1, 4, 0, 1, 1);
    gbox->addWidget(pb0, 5, 0, 1, 1.5);

    gbox->addWidget(pb8, 2, 1, 1, 1);
    gbox->addWidget(pb5, 3, 1, 1, 1);
    gbox->addWidget(pb2, 4, 1, 1, 1);
    gbox->addWidget(pbpot,5,2, 1, 1.5);
    gbox->addWidget(pbdel,1,2, 1, 2);

    gbox->addWidget(pb9, 2, 2, 1, 1);
    gbox->addWidget(pb6, 3, 2, 1, 1);
    gbox->addWidget(pb3, 4, 2, 1, 1);

    setLayout(gbox);

    connect(pb0,SIGNAL(clicked(bool)),this,SLOT(my_counter()));
    connect(pb1,SIGNAL(clicked(bool)),this,SLOT(my_counter()));
    connect(pb2,SIGNAL(clicked(bool)),this,SLOT(my_counter()));
    connect(pb3,SIGNAL(clicked(bool)),this,SLOT(my_counter()));
    connect(pb4,SIGNAL(clicked(bool)),this,SLOT(my_counter()));
    connect(pb5,SIGNAL(clicked(bool)),this,SLOT(my_counter()));
    connect(pb6,SIGNAL(clicked(bool)),this,SLOT(my_counter()));
    connect(pb7,SIGNAL(clicked(bool)),this,SLOT(my_counter()));
    connect(pb8,SIGNAL(clicked(bool)),this,SLOT(my_counter()));
    connect(pb9,SIGNAL(clicked(bool)),this,SLOT(my_counter()));

    connect(pba,SIGNAL(clicked(bool)),this,SLOT(my_add()));
    connect(pbb,SIGNAL(clicked(bool)),this,SLOT(my_minus()));
    connect(pbc,SIGNAL(clicked(bool)),this,SLOT(my_multiply()));
    connect(pbd,SIGNAL(clicked(bool)),this,SLOT(my_division()));
    connect(pb,SIGNAL(clicked(bool)),this,SLOT(my_equal()));

    connect(pbclr,SIGNAL(clicked(bool)),this,SLOT(my_ac()));
}

myWidget::~myWidget()
{

}

void myWidget::my_add()
{
    flag = 1;
}

void myWidget::my_minus()
{
    flag = 2;
}

void myWidget::my_multiply()
{
    flag = 3;
}

void myWidget::my_division()
{
    flag = 4;
}

void myWidget::my_counter()
{
    if(flag == 0&&num1 ==-1)
    {
        QPushButton *p = static_cast<QPushButton*>(sender());
        QString str = p->text();
        num1 = str.toInt();
        le->clear();
        le->setText(str);
    }
    if(flag!=0&&num1 == -1)
    {
        QString *str = strArr.data();
        num1 = str->toInt();
    }
    else{
        QPushButton *p = static_cast<QPushButton*>(sender());
        QString str = p->text();
        le->setText(str);
        num2 = str.toInt();
    }
}

void myWidget::my_equal()
{
    if(flag == 1)
    {
        sum = num1+num2;
    }else if(flag == 2)
    {
        sum = num1-num2;
    }else if(flag == 3)
    {
        sum = num1*num2;
    }else if(flag == 4)
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
    le->setText(0);
}

