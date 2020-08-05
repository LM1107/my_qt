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

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(le);
    vbox->addWidget(cbb);
    setLayout(vbox);
}

Widget::~Widget()
{

}

/*
void Widget::getText()
{
    QString str =  cbb->currentText();
    le->setText();
}
*/
