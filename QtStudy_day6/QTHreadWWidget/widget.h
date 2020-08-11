#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QTimeEdit>
#include <QDebug>
#include <QThread>
#include "subthread.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QTimeEdit *te;
    QTimer *t;
    int flag;
    subThread *st;
private slots:
    void showTime();
};

#endif // WIDGET_H
