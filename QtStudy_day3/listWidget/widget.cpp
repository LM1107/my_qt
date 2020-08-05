#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    pb1 = new QPushButton(">>");
    pb2 = new QPushButton("<<");
    lw1 = new QListWidget;
    lw2 = new QListWidget;

    lw1->addItem("A");
    QListWidgetItem *item = new QListWidgetItem
    lw1->addItem();

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addStretch();
    vbox->addWidget(pb1);
    vbox->addWidget(pb2);
    vbox->addStretch();

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addWidget(lw1);
    hbox->addLayout(vbox);
    hbox->addWidget(lw2);
    setLayout(hbox);
}

Widget::~Widget()
{

}
