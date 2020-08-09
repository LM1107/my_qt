#include "mypushbutton.h"

myPushbutton::myPushbutton(QWidget *parent)
    :QPushButton(parent)
{

}

void myPushbutton::keyReleaseEvent(QKeyEvent *event)
{
    //QKeyEvent *e = static_cast<QKeyEvent*>(event);
    if(event->key() == Qt::Key_Up)
        emit keyPressUp(true);
    else if(event->key() == Qt::Key_Down)
        emit keyPressDown(true);
    else
        return;
}
