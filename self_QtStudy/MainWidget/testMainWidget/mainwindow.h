#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QLabel>
#include <QStatusBar>
#include <QTextEdit>
#include <QDockWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QPushButton *pb1;
private slots:
    void actionTriggered();
};

#endif // MAINWINDOW_H
