#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QDebug>
#include <QHBoxLayout>
#include <QGroupBox>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QRadioButton *rp1,*rp2,*rp3,*rp4;
    QRadioButton *rb[4];
    QLabel *l,*l2;
    QGroupBox *gbox1,*gbox2;
private slots:
    void show_radioButton();
};

#endif // WIDGET_H
