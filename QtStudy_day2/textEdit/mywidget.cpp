
#include "mywidget.h"

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    pb1 = new QPushButton("te->le",this);
    pb2 = new QPushButton("le->te",this);
    le = new QLineEdit;
    te = new QTextEdit;

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addWidget(pb1);
    hbox->addWidget(pb2);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(te);
    vbox->addWidget(le);
    vbox->addLayout(hbox);

    setLayout(vbox);

    connect(pb1,SIGNAL(clicked(bool)),this,SLOT(textToLine()));
    connect(pb2,SIGNAL(clicked(bool)),this,SLOT(lineToText()));

}

myWidget::~myWidget()
{

}

void myWidget::textToLine()
{
    QString str = te->toPlainText(); //获取文本编辑器的纯文本
    //QString str = te->toHtml();    //获取文本编辑器的内容，包括格式。
    le->setText(str);
    qDebug() << str;
}

void myWidget::lineToText()
{
    QString str = le->text();
    te->setText(str);       //设置文本编辑器的内容
    qDebug() << str;
}
