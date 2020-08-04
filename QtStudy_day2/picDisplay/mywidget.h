#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QPushButton>
#include <QDebug>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "subwidget.h"

class myWidget : public QWidget
{
    Q_OBJECT

public:
    myWidget(QWidget *parent = 0);
    ~myWidget();
private:
    QPushButton *pbopen;

private slots:
    void openFile();
};

#endif // MYWIDGET_H
