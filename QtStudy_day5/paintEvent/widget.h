#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QMouseEvent>
#include <QPixmap>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QPoint point;
    QPixmap *pixmap;
protected:
    void paintEvent(QPaintEvent *event);

    //void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);
};

#endif // WIDGET_H
