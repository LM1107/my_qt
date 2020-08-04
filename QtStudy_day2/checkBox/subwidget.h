#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

class subWidget : public QWidget
{
    Q_OBJECT
public:
    explicit subWidget(QWidget *widget,QWidget *parent = nullptr);

signals:

public slots:
    void returnWidget();
private:
    QPushButton *pb1,*pb2;
    QWidget *w;
};

#endif // SUBWIDGET_H
