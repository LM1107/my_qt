#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QObject>
#include <QWidget>
#include <QEvent>
#include <QPushButton>
#include <QKeyEvent>

class myPushbutton : public QPushButton
{
    Q_OBJECT
public:
    myPushbutton(QWidget *parent);
protected:
    void keyReleaseEvent(QKeyEvent *event);
signals:
    void keyPressUp(bool);
    void keyPressDown(bool);
private slots:
};

#endif // MYPUSHBUTTON_H
