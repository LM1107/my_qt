#include<QApplication>
#include <QWidget>  //窗口控件基类
#include <QPushButton>

int main(int argc,char *argv[])
{
    QApplication a(argc,argv);

    QWidget w;
    w.setWindowTitle("Death");  //设置标题

    /*  如果不指定父对象，对象和对象（窗口和窗口）没有关系，独立
     *  a指定b为它的父对象，a放在b的里面。
     *  指定父对象，有两种方式：
     *              1)serParent
     *              2)通过构造函数传参
     *  指定父对象，只需要父对象显示，上面的子对象自动显示
     */

    QPushButton pb;
    pb.setText("OK");
    pb.setParent(&w);   //指定父对象
    pb.move(250,250);    //移动坐标

    QPushButton pb1(&w);    //通过构造函数传参
    pb1.setText("CANCLE");

    w.show();

    a.exec();
    return 0;
}
