#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>

class myWidget : public QWidget
{
    Q_OBJECT

public:
    myWidget(QWidget *parent = 0);
    ~myWidget();
private slots:
    void textToLine();
    void lineToText();
private:
    QTextEdit *te;
    QLineEdit *le;
    QPushButton *pb1,*pb2;
};

#endif // MYWIDGET_H
