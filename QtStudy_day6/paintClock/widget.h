#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QPixmap>
#include <QTime>
#include <QTimer>
#include <QDebug>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QPixmap *pixmap;
    QTimer *t;
protected:
    void paintEvent(QPaintEvent *event);
private slots:

};

#endif // WIDGET_H
