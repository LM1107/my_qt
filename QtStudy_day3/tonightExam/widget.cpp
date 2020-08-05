#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    score = 0.0;

    QFont font("Times",20,QFont::Bold);
    QFont fontp("Times",20,QFont::Normal);
    l1 = new QLabel("第一题：int i=1,j=1,k=2;if((j++||k++)&&i++)printf(\"%d,%d,%d\\n\",i,j,k);打印结果为多少？");
    l1->setFont(font);
    l1->setFixedSize(500,300);
    l1->adjustSize();
    l1->setWordWrap(true);
    l1->setAlignment(Qt::AlignTop);

    QStringList list1 = {"A.1,1,2","B.2,2,1","C.2,2,2","D.2,2,3"};
    for(int i=0;i<4;i++)
    {
        ra[i] = new QRadioButton(list1.at(i));
        ra[i]->setFont(fontp);
    }

    answer1 = "C.2,2,2";

    QVBoxLayout *vbox1 = new QVBoxLayout;
    vbox1->addWidget(l1);
    for(int i=0;i<4;i++)
        vbox1->addWidget(ra[i]);

    gbox1 = new QGroupBox("第一题");
    gbox1->setLayout(vbox1);

    l2 = new QLabel("第二题：计算机工作时，内存储器用来存储()");
    l2->setFont(font);
    l2->setFixedSize(500,300);
    l2->adjustSize();
    l2->setWordWrap(true);
    l2->setAlignment(Qt::AlignTop);

    QStringList list2 = {"A.program&&order","B.data&&signal","C.program&&data","D.ASC II&&data"};
    for(int i=0;i<4;i++)
    {
        rb[i] = new QRadioButton(list2.at(i));
        rb[i]->setFont(fontp);
    }

    answer2 = "C.program&&data";

    QVBoxLayout *vbox2 = new QVBoxLayout;
    vbox2->addWidget(l2);
    for(int i=0;i<4;i++)
        vbox2->addWidget(rb[i]);

    gbox2 = new QGroupBox("第二题");
    gbox2->setLayout(vbox2);


    l3 = new QLabel("第三题：char s[]=\"\\\\123456\\123456\\t,printf(\"%d\\n\",strlen(s));");
    l3->setFont(font);
    l3->setFixedSize(500,300);
    l3->adjustSize();
    l3->setWordWrap(true);
    l3->setAlignment(Qt::AlignTop);

    QStringList list3 = {"A.12","B.13","C.16","D.allWrong"};
    for(int i=0;i<4;i++)
    {
        rc[i] = new QRadioButton(list3.at(i));
        rc[i]->setFont(fontp);
    }

    answer3 = "A.12";

    QVBoxLayout *vbox3 = new QVBoxLayout;
    vbox3->addWidget(l3);
    for(int i=0;i<4;i++)
        vbox3->addWidget(rc[i]);

    gbox3 = new QGroupBox("第三题");
    gbox3->setLayout(vbox3);

    pbover = new QPushButton("提交",this);
    pbover->setFixedSize(75,50);

    cbb = new QComboBox;
    cbb->addItem("No.1");
    cbb->addItem("No.2");
    cbb->addItem("No.3");

    sw = new QStackedWidget;
    sw->addWidget(gbox1);
    sw->addWidget(gbox2);
    sw->addWidget(gbox3);

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addStretch();
    hbox->addWidget(cbb);
    hbox->addStretch();

    QHBoxLayout *hbox1 = new QHBoxLayout;
    hbox1->addStretch();
    hbox1->addStretch();
    hbox1->addStretch();
    hbox1->addWidget(pbover);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addLayout(hbox1);
    vbox->addWidget(sw);
    vbox->addLayout(hbox);
    setLayout(vbox);

    connect(cbb,SIGNAL(currentIndexChanged(int)),this,SLOT(setStackWidget()));
    connect(pbover,SIGNAL(clicked(bool)),this,SLOT(checkAnswer()));
}

Widget::~Widget()
{

}

void Widget::setStackWidget()
{
    int count = cbb->currentIndex();
    sw->setCurrentIndex(count);
}

void Widget::checkAnswer()
{
    if(ra[2]->isChecked())
        score+=33.3;
    if(rb[2]->isChecked())
        score+=33.3;
    if(rc[0]->isChecked())
        score+=33.3;
    subWidget *sw = new subWidget(score);
    sw->show();
}
