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
    QPushButton *pb_expr[5];
    QPushButton *pb_num[10];
    QPushButton *pbpot,*pbclr,*pbdel;
    QLineEdit *le;
    double num1;
    double num2;
    double sum;
    int flag;
    int flagp;
    QString temp;

private slots:
    void my_add();
    void my_minus();
    void my_multiply();
    void my_division();
    void my_counter();
    void my_equal();
    void my_ac();
    void point_clicked();
};

#endif // MYWIDGET_H
