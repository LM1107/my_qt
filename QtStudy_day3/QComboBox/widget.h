#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QVBoxLayout>
#include <QDebug>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QLineEdit *le;
    QComboBox *cbb;
private slots:
    void getText();
    void getText(QString);
};

#endif // WIDGET_H
