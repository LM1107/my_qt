#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QStringList filenames = QFileDialog::getOpenFileNames(this, "Open", ".", "Images(*.jpg)");

}

Widget::~Widget()
{

}
