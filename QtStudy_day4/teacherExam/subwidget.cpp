#include "subwidget.h"

subWidget::subWidget(int score,QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(400,400);
    QFont font("Times",15,QFont::Bold);
    l = new QLabel("this");
    l->setFont(font);
    l->setFixedSize(300,300);
    l->setAlignment(Qt::AlignCenter);
    l->setText(QString("你的得分是：%1").arg(score));

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addStretch();
    hbox->addWidget(l);
    hbox->addStretch();
    setLayout(hbox);
}
