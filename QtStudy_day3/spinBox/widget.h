#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSpinBox>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QDebug>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QLineEdit *le;
    QSpinBox *sb;
    QDoubleSpinBox *dsb;
private slots:
    void setVal(int);
    void setDVal(double);
};

#endif // WIDGET_H
