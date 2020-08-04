#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QVector>

class myWidget : public QWidget
{
    Q_OBJECT

public:
    myWidget(QWidget *parent = 0);
    ~myWidget();
private:
    QPushButton *pba,*pbb,*pbc,*pbd,*pb;
    QPushButton *pb0,*pb1,*pb2,*pb3,*pb4,*pb5,*pb6,*pb7,*pb8,*pb9;
    QPushButton *pbpot,*pbclr,*pbdel;
    QLineEdit *le;
    int num1;
    int num2;
    int sum;
    int flag;
    int temp;

private slots:
    void my_add();
    void my_minus();
    void my_multiply();
    void my_division();
    void my_counter();
    void my_equal();
    void my_ac();
};

#endif // MYWIDGET_H
