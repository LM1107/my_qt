#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    le = new QLineEdit("A");
    cbb = new QComboBox;
    cbb->addItem("A");
    cbb->addItem(QIcon(":/pic/1.jpg"),"left");
    QStringList list = {"B","C","D"};
    cbb->addItems(list);
    cbb->insertItem(1,QIcon(":/pic/2.jpg"),"up");


    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(le);
    vbox->addWidget(cbb);
    setLayout(vbox);

//    connect(cbb,SIGNAL(currentIndexChanged(QString)),this,SLOT(getText())); //当选择条目改变时
    connect(cbb,SIGNAL(currentIndexChanged(QString)),this,SLOT(getText(QString))); //当选择条目改变时

}

Widget::~Widget()
{

}

void Widget::getText()
{
    QString str =  cbb->currentText();  //获取当前条目内容
    le->setText(str);
}

void Widget::getText(QString str)
{
    le->setText(str);
}
