#include "mywidget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    cout<<"Hello Qt"<<endl;
    cout<<"hello Qt!"<<endl;

    this->setFixedSize(640,480);    //设置窗口的固定大小
//    this->setMaximumSize(640,480);  //设置窗口的最大值
//    this->setMinimumSize(640,480);  //设置窗口的最小值
    this->setWindowIcon(QIcon("1.jpg")); //设置窗口的图标
    this->setWindowTitle("Hello_Qt");   //设置窗口名字
}

Widget::~Widget()
{

}
