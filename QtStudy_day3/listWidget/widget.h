#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <QListWidgetItem>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QPushButton *pb1,*pb2;
    QListWidget *lw1,*lw2;
private slots:
    void leftToRight();
    void rightToLeft();
};

#endif // WIDGET_H
