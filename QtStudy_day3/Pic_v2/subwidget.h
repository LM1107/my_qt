#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "mypushbutton.h"

class subWidget : public QWidget
{
    Q_OBJECT
public:
    explicit subWidget(QString str1,int s,QWidget *widget,QWidget *parent = nullptr);
    QLabel *l;
    myPushbutton *pbn;
    myPushbutton *pbp;
    QPixmap *pic;
    QWidget *w;
    QStringList filelist;
    int size;

    int flag;
signals:

public slots:
    void turnUp();
    void turnDown();
};


#endif // SUBWIDGET_H
