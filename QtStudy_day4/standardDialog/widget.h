#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QDebug>
#include <QFile>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QPushButton *pb_file,*pb_msg,*pb_input,*pb_font,*pb_color;
    QTextEdit *te;
private slots:
    void openFile();
    void showMsg();
    void inputData();
    void choseColor();
    void choseFont();

};

#endif // WIDGET_H
