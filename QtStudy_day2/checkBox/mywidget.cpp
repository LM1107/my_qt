#include "mywidget.h"

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    pb_log = new QPushButton("Login");
    pb_reg = new QPushButton("register");
    l_name = new QLabel("username:");
    l_passwd = new QLabel("Passwd:");
    le_name = new QLineEdit;
    le_passwd = new QLineEdit;
    //le_passwd->setEchoMode(QLineEdit::Password);
    le_passwd->setInputMask("N");   //设置输入的格式
    cb_user = new QCheckBox("记住密码");
    cb_showpd = new QCheckBox("显示密码");

    QHBoxLayout *hbox1 = new QHBoxLayout;
    hbox1->addWidget(l_name);
    hbox1->addWidget(le_name);
    hbox1->addWidget(cb_user);

    QHBoxLayout *hbox2 = new QHBoxLayout;
    hbox2->addWidget(l_passwd);
    hbox2->addWidget(le_passwd);
    hbox2->addWidget(cb_showpd);

    QHBoxLayout *hbox3 = new QHBoxLayout;
    hbox3->addWidget(pb_log);
    hbox3->addStretch();
    hbox3->addWidget(pb_reg);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addLayout(hbox1);
    vbox->addLayout(hbox2);
    vbox->addLayout(hbox3);

    setLayout(vbox);

    connect(cb_showpd,SIGNAL(clicked(bool)),this,SLOT(myShowpd()));
    connect(pb_log,SIGNAL(clicked(bool)),this,SLOT(jump_sub()));
}

myWidget::~myWidget()
{

}

void myWidget::myShowpd()
{
    if(cb_showpd->isChecked())
    {
        le_passwd->setEchoMode(QLineEdit::Normal);
    }else{
        le_passwd->setEchoMode(QLineEdit::Password);
    }
}

void myWidget::jump_sub()
{
    subWidget *sw = new subWidget(this);
    sw->show();
    this->hide();
}
