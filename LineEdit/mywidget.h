#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include <QVBoxLayout>

class myWidget : public QWidget
{
    Q_OBJECT

public:
    myWidget(QWidget *parent = 0);
    ~myWidget();
private:
    QLineEdit *le;
    QPushButton *pb;
private slots:
    void show_le();
};

#endif // MYWIDGET_H
