#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    le = new QLineEdit;
    cbb = new QComboBox;
    cbb->addItem("A");
    cbb->addItem(":/pic/left.jpg");
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

void Widget::getText()
{
    QString str =  cbb->currentText();
    le->setText();
}
