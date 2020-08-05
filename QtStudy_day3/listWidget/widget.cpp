#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    pb1 = new QPushButton(">>");
    pb2 = new QPushButton("<<");
    lw1 = new QListWidget;
    lw2 = new QListWidget;

    lw1->addItem("A");
    QListWidgetItem *item = new QListWidgetItem(QIcon(":/pic/1.jpg"),"Rosie");
    lw1->addItem(item);

    QStringList list = {"B","C","D"};
    lw2->addItems(list);


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

    connect(pb1,SIGNAL(clicked(bool)),this,SLOT(leftToRight()));
    connect(pb2,SIGNAL(clicked(bool)),this,SLOT(rightToLeft()));

}

Widget::~Widget()
{

}

void Widget::leftToRight()
{
    //QListWidgetItem *item = lw1->currentItem();
    //QListWidgetItem *item = lw1->takeItem(lw1->currentRow());
    QListWidgetItem *item = new QListWidgetItem(lw1->takeItem(lw1->currentRow()));
    lw2->addItem(item);
}

void Widget::rightToLeft()
{
    QListWidgetItem *item = lw2->takeItem(lw2->currentRow());
    lw1->addItem(item);
}
