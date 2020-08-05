#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSlider>      //滑动条
#include <QScrollBar>       //滚动条
#include <QProgressBar>         //进度条
#include <QVBoxLayout>
#include <QDebug>
#include <QLineEdit>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QScrollBar *sb;
    QSlider *sd;
    QProgressBar *pgb;
    QLineEdit *le;
private slots:
    void setValues();
};

#endif // WIDGET_H
