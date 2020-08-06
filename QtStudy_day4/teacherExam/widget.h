#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGroupBox>
#include <QLabel>
#include <QRadioButton>
#include <QTimer>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <QPushButton>
#include <QLineEdit>
#include "subwidget.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QLabel *l_score,*l_time,*l[3];
    QPushButton *pb_next,*pb_submit;
    QRadioButton *rb[3][4];
    QGroupBox *gbox[3];
    QLineEdit *le_score,*le_time;
    QStackedWidget *sw;
    QTimer *time;
    int answers[3];
    int count;
    double score;
private slots:
    void nextQuestion();
    void submitPaper();
    void countDown();
};

#endif // WIDGET_H
