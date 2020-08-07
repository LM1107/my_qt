#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    le1 = new QLineEdit;
    le2 = new QLineEdit;
    le3 = new QLineEdit;
    pb1 = new QPushButton("Ok");
    pb2 = new QPushButton("Cancle");

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addWidget(pb1);
    hbox->addWidget(pb2);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(le1);
    vbox->addWidget(le2);
    vbox->addWidget(le3);
    vbox->addLayout(hbox);
    setLayout(vbox);

    le1->installEventFilter(this);  //安装事件过滤器
    le2->installEventFilter(this);
    le3->installEventFilter(this);
    pb1->installEventFilter(this);
    pb2->installEventFilter(this);

}

Widget::~Widget()
{

}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==le1||watched==le2||watched==le3)
    {
        if(event->type()==QEvent::KeyPress) //当事件是键盘按下事件时
        {
            QKeyEvent *e = static_cast<QKeyEvent*>(event);
            if(e->key() == Qt::Key_Return)
            {
                QLineEdit *le = static_cast<QLineEdit*>(watched);
                qDebug() << le->text();
                return true;
            }else if(e->key() == Qt::Key_Up)
            {
                this->focusPreviousChild();
                return true;
            }else if(e->key() == Qt::Key_Down)
            {
                this->focusNextChild();
                return true;
            }else{
                return false;
            }
        }else
            return false;
    }else if(watched==pb1||watched==pb2)
    {
        if(event->type() == QEvent::KeyPress)
        {
            QKeyEvent *e = static_cast<QKeyEvent*>(event);
            if(e->key() == Qt::Key_Up)
            {
                this->focusPreviousChild();
                return true;
            }else if(e->key() == Qt::Key_Down)
            {
                this->focusNextChild();
                return true;
            }else
                return false;
        }else{
            return false;
        }
    }
    return QWidget::eventFilter(watched,event);
}
