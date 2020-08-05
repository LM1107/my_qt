#include "mywidget.h"

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    pbopen = new QPushButton("open file",this);
    QFont font("Times",30,QFont::Bold);
    pbopen->setFont(font);
    pbopen->setFixedSize(250,250);
    pbopen->move(250,250);

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addStretch();
    hbox->addWidget(pbopen);
    hbox->addStretch();

    QHBoxLayout *hbox1 = new QHBoxLayout;
    hbox1->addStretch();
    QHBoxLayout *hbox2 = new QHBoxLayout;
    hbox2->addStretch();

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addLayout(hbox1);
    vbox->addLayout(hbox);
    vbox->addLayout(hbox2);

    setLayout(vbox);

    connect(pbopen,SIGNAL(clicked(bool)),this,SLOT(openFile()));
}

myWidget::~myWidget()
{

}

void myWidget::openFile()
{
    //QStringList filenames;// = QFileDialog::getOpenFileNames(this,"open file",".","Image Files(*.png *.jpg *.bmp)");
    QStringList filenames = QFileDialog::getOpenFileNames(this, "OPen files", ".", "Images(*.jpg)");

    qDebug() << filenames;
    if(filenames.isEmpty())
        return;
    /*
    int size = filenames.size();
    QString str = filenames.join(",");
    qDebug() << str;
    subWidget *sw = new subWidget(str,size,this);
    this->hide();
    sw->show();
    */
}
