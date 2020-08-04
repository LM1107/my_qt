#include "subwidget.h"

subWidget::subWidget(QString str1,int s,QWidget *widget,QWidget *parent) : QWidget(parent)
{
    w = widget;
    size = s;
    flag = 0;
    filelist = str1.split(",");

    l = new QLabel("pic",this);

    pbp = new QPushButton;
    pbp->setIcon(QIcon(":/pic/left.jpg"));
    pbp->setIconSize(QSize(75,75));
    pbp->setFixedSize(75,75);
    pbp->setEnabled(false);

    pbn = new QPushButton;
    pbn->setIcon(QIcon(":/pic/right.jpg"));
    pbn->setIconSize(QSize(75,75));
    pbp->setFixedSize(75,75);
    pbn->setEnabled(true);

    l->setPixmap(QPixmap(filelist[flag]));
    l->setScaledContents(true);

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addWidget(pbp);
    hbox->addStretch();
    hbox->addWidget(l);
    hbox->addStretch();
    hbox->addWidget(pbn);
    setLayout(hbox);

    connect(pbp,SIGNAL(clicked(bool)),this,SLOT(turnUp()));
    connect(pbn,SIGNAL(clicked(bool)),this,SLOT(turnDown()));
}

void subWidget::turnUp()
{
    if(flag<=0)
        pbp->setEnabled(false);
    else
        flag--;
    pbn->setEnabled(true);
    l->setPixmap(QPixmap(filelist[flag]));
}

void subWidget::turnDown()
{
    if(flag>=(size-1))

        pbn->setEnabled(false);
    else
        flag++;
    pbp->setEnabled(true);
    l->setPixmap(QPixmap(filelist[flag]));

}
