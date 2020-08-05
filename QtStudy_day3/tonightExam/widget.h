#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <QGroupBox>
#include <QRadioButton>
#include <QLabel>
#include <QPushButton>
#include "subwidget.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QRadioButton *ra[4];
    QRadioButton *rb[4];
    QRadioButton *rc[4];
    QGroupBox *gbox1,*gbox2,*gbox3;
    QComboBox *cbb;
    QStackedWidget *sw;
    QLabel *l1,*l2,*l3;
    QPushButton *pbover;
    QString answer1;
    QString answer2;
    QString answer3;
    double score;
private slots:
    void setStackWidget();
    void checkAnswer();
};

#endif // WIDGET_H
