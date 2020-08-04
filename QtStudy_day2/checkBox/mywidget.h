#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include "subwidget.h"

class myWidget : public QWidget
{
    Q_OBJECT

public:
    myWidget(QWidget *parent = 0);
    ~myWidget();

private:
    QPushButton *pb_log,*pb_reg;
    QLabel *l_name,*l_passwd;
    QLineEdit *le_name,*le_passwd;
    QCheckBox *cb_user,*cb_showpd;
private slots:
    void myShowpd();
    void jump_sub();
};

#endif // MYWIDGET_H
