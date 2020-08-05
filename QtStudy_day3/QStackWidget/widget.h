#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <QLabel>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QComboBox *cbb;
    QStackedWidget *sw;
    QLabel *l1,*l2,*l3;
private slots:
    void setStackWidget();
};

#endif // WIDGET_H
