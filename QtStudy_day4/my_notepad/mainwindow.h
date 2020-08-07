#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QStatusBar>
#include <QToolBar>
#include <QAction>
#include <QLabel>
#include <QTextEdit>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QTextEdit *te;
    QMenu *menu[4];
//    QMenu *menuWindow;
    QToolBar *filetool;
    QAction *Act[4][3];
//    QAction *ActWindow;
    QMenuBar *mBar;
    QLabel *l[4];
    QString filename;
private slots:
    void newFile();
    void openFile();
    void saveFile();
    void saveasFile();
};

#endif // MAINWINDOW_H
