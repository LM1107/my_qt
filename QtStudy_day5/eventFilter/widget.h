#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QDebug>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QEvent>
#include <QKeyEvent>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
protected:
    bool eventFilter(QObject *watched, QEvent *event);
private:
    QLineEdit *le1,*le2,*le3;
    QPushButton *pb1,*pb2;
};

#endif // WIDGET_H
