#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    pb = new QPushButton("show");
    mw = new myWoget;

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(pb);
    vbox->addWidget(mw);
    setLayout(vbox);

    connect(pb,SIGNAL(clicked(bool)),this,SLOT(showClicked()));
}

Dialog::~Dialog()
{

}

void Dialog::showClicked()
{
    qDebug() << "show clicked";
}
