#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QTimeEdit>    //时间编辑器
#include <QDateTimeEdit>    //日期编辑器
#include <QTime>        //时间
#include <QDateTime>    //日期
#include <QVBoxLayout>
//#include <QThread>
#include <QTimer>   //定时器

class myWidget : public QWidget
{
    Q_OBJECT

public:
    myWidget(QWidget *parent = 0);
    ~myWidget();
private:
    QTimeEdit *te;
    QDateTimeEdit *dte;
    QTimer *timer;
private slots:
    void changeTime();
};

#endif // MYWIDGET_H
