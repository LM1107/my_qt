#ifndef MYWOGET_H
#define MYWOGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QDebug>

class myWoget : public QWidget
{
    Q_OBJECT
public:
    explicit myWoget(QWidget *parent = nullptr);

signals:

public slots:
    void okClicked();
    void cancleClicked();
private:
    QPushButton *pb1,*pb2;

};

#endif // MYWOGET_H
