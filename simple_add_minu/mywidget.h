#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <QLineEdit>

class myWidget : public QWidget
{
    Q_OBJECT

public:
    myWidget(QWidget *parent = 0);
    ~myWidget();
private:
    QPushButton *pb1,*pb2;
    QLineEdit *le;
    int num;
private slots:
    void my_add();
    void my_minus();

};

#endif // MYWIDGET_H
