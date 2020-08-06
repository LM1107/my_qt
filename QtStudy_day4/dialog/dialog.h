#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include "mywoget.h"
#include <QDebug>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
private:
    QPushButton *pb;
    myWoget *mw;
private slots:
    void showClicked();
};

#endif // DIALOG_H
