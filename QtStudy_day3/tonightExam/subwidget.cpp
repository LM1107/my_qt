#include "subwidget.h"

subWidget::subWidget(double score,QWidget *parent) : QWidget(parent)
{
    s = score;
    l = new QLabel;
    QFont font("Times",20,QFont::Bold);
    l->setText("你最后的成绩是:"+QString::number(s));
    l->setFixedSize(400,100);
    l->setFont(font);
    l->adjustSize();
    l->setWordWrap(true);
    l->setAlignment(Qt::AlignTop);

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addStretch();
    hbox->addWidget(l);
    hbox->addStretch();

    setLayout(hbox);
}
