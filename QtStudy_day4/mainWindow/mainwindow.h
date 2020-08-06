#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QAction>
#include <QStatusBar>
#include <QTextEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QAction *newAct,*openAct;
    QMenu *fileMenu,*editMenu;
    QToolBar *filetool;
    QTextEdit *te;
};

#endif // MAINWINDOW_H
