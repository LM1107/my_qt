#include "subwidget.h"

subWidget::subWidget(QString str1,int s,QWidget *widget,QWidget *parent) : QWidget(parent)
{
    w = widget;
    size = s;
    flag = 0;
    filelist = str1.split(",");

    l = new QLabel("pic",this);
    l->setFixedSize(680,480);

    pbp = new QPushButton(this);
    pbp->setIcon(QIcon(":/pic/left.jpg"));
    pbp->setIconSize(QSize(75,75));
    pbp->setFixedSize(75,75);
    pbp->setEnabled(false);
    pbp->setFlat(true);

    pbn = new QPushButton(this);
    pbn->setIcon(QIcon(":/pic/right.jpg"));
    pbn->setIconSize(QSize(75,75));
    pbn->setFixedSize(75,75);
    pbn->setEnabled(true);
    pbn->setFlat(true);

    pic = new QPixmap(filelist[flag]);
    pic->scaled(l->size(),Qt::KeepAspectRatio);
    l->setScaledContents(true);
    l->setPixmap(*pic);

//    QHBoxLayout *hbox = new QHBoxLayout;
//    hbox->addWidget(pbp);
//    hbox->addStretch();
//    hbox->addWidget(l);
//    hbox->addStretch();
//    hbox->addWidget(pbn);
//    setLayout(hbox);

    pbp->setGeometry(0,300,75,75);
    pbn->setGeometry(600,300,50,50);

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
    pic = new QPixmap(filelist[flag]);
    pic->scaled(l->size(),Qt::KeepAspectRatio);
    l->setScaledContents(true);
    l->setPixmap(*pic);
}

void subWidget::turnDown()
{
    if(flag>=(size-1))

        pbn->setEnabled(false);
    else
        flag++;
    pbp->setEnabled(true);
    pic = new QPixmap(filelist[flag]);
    pic->scaled(l->size(),Qt::KeepAspectRatio);
    l->setScaledContents(true);
    l->setPixmap(*pic);

}

void subWidget::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();
    if(key == Qt::Key_Up)
        turnUp();
    else if(key == Qt::Key_Down)
        turnDown();
}

