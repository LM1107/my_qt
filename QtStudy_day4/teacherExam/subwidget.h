#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

class subWidget : public QWidget
{
    Q_OBJECT
public:
    explicit subWidget(int score,QWidget *parent = nullptr);
private:
    QLabel *l;
signals:

public slots:
};

#endif // SUBWIDGET_H
