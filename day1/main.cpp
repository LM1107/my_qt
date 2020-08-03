#include "mywidget.h"

//QApplication应用程序类   GUI界面管理的类，初始化，回收资源
//Qt头文件没有.h
//头文件和类名一样
#include <QApplication>

int main(int argc, char *argv[])
{
    //有且只有一个应用程序类的对象
    QApplication a(argc, argv);
    //Widget继承于QWidget，QWidget是一个窗口基类
    //所以Widget也是窗口类
    //w就是一个窗口
    Widget w;

    //窗口创建默认是隐藏的，需要人为显示
    w.show();

    //让程序一直执行，等待用户操作
    //等待事件的发生
    //a.exec();
    //return 0;
    return a.exec();
    //把程序的控制权交给Qt
}
