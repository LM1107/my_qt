#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <iostream>
#include <QDebug>   //调试
#include <QIcon>
using namespace std;

class Widget : public QWidget
{
    //Qt有两种核心工作机制：1、信号与槽；2、事件
    Q_OBJECT    //信号与槽需要的宏

public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // MYWIDGET_H
