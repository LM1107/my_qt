#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    score = 0.0;

    l_time = new QLabel("倒计时：");
    l_score = new QLabel("得分：");
    le_time = new QLineEdit("10");
    le_time->setReadOnly(true);
    le_score = new QLineEdit("0");
    le_score->setReadOnly(true);

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addWidget(l_time);
    hbox->addWidget(le_time);
    hbox->addStretch();
    hbox->addWidget(l_score);
    hbox->addWidget(le_score);

    pb_next = new QPushButton("下一题");
    pb_submit = new QPushButton("提交");
    QHBoxLayout *hbox1 = new QHBoxLayout;
    hbox1->addWidget(pb_next);
    hbox1->addStretch();
    hbox1->addWidget(pb_submit);

    QStringList questions = {"1+1 = ?","1+2 = ?","1+3 = ?"};
    QStringList group = {"第一题","第二题","第三题"};
    QStringList answers = {"0","1","2","3","2","3","4","5","3","4","5","6"};
    QVBoxLayout *vbox[3];

    for(int i=0;i<3;i++)
    {
        vbox[i] = new QVBoxLayout;
        l[i] = new QLabel(questions.at(i));
        vbox[i]->addWidget(l[i]);
        gbox[i] = new QGroupBox(group.at(i));
        for(int j=0;j<4;j++){
            rb[i][j] = new QRadioButton(answers.at(i*4+j));
            vbox[i]->addWidget(rb[i][j]);
        }
    }

    sw = new QStackedWidget;
    for(int i=0;i<3;i++){
        gbox[i]->setLayout(vbox[i]);
        sw->addWidget(gbox[i]);
    }

    QVBoxLayout *vbox1 = new QVBoxLayout;
    vbox1->addLayout(hbox);
    vbox1->addWidget(sw);
    vbox1->addLayout(hbox1);
    setLayout(vbox1);

    answers[0]=2;
    answers[1]=1;
    answers[2]=1;
    count = 10;

    time = new QTimer;
    time->start(1000);

    connect(pb_next,SIGNAL(clicked(bool)),this,SLOT(nextQuestion()));
    connect(pb_submit,SIGNAL(clicked(bool)),this,SLOT(submitPaper()));
    connect(time,SIGNAL(timeout()),this,SLOT(countDown()));
}

Widget::~Widget()
{

}

void Widget::nextQuestion()
{
    int index = sw->currentIndex();     //获取当前页码
    int count = sw->count();     //获取总共的页数
    if(index == count)
    {
        submitPaper();
        return;
    }
    if(rb[index][answers[index]]->isChecked())
        score+=33.3;
    sw->setCurrentIndex(index+1);
    le_score->setText(QString::number(score));
    count = 10;
    le_time->setText(QString::number(count));
}

void Widget::submitPaper()
{
    int index = sw->currentIndex();     //获取当前页
    if(rb[index][answers[index]]->isChecked())
        score+=33.3;
    time->stop();
    subWidget *subw = new subWidget(score);
    subw->show();
}

void Widget::countDown()
{
    if(count == 0)
        nextQuestion();
    else{
        count--;
        le_time->setText(QString::number(count));
    }
}

