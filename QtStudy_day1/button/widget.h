#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>      //水平布局
#include <QVBoxLayout>      //垂直布局
#include <QDebug>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QPushButton *pb,*pbb;
private slots:
    void show_clicked_OK();
    //void show_clicked_CAN();
};

#endif // WIDGET_H
