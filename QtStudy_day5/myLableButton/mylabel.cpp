#include "mylabel.h"

myLabel::myLabel(QString str)
    :QLabel(str)
{

}

//当鼠标点击myLable,会自动发射clicked信号
void myLabel::mousePressEvent(QMouseEvent *event)
{
    emit clicked(true);     //发射信号
}

void myLabel::mouseReleaseEvent(QMouseEvent *event)
{
    emit release(true);
}
