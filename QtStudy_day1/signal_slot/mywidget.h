#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QDebug>

class myWidget : public QWidget
{
    Q_OBJECT

public:
    myWidget(QWidget *parent = 0);
    ~myWidget();

private:
    QPushButton *pb1,*pb2;
private slots:
    void OK_CLICKED();
    void CAN_CLICKED();
};

#endif // MYWIDGET_H
