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
    explicit subWidget(double score,QWidget *parent = nullptr);

signals:

public slots:

private:
    QLabel *l;
    double s;
};

#endif // SUBWIDGET_H
