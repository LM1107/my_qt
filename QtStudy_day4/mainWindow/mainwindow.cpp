#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    newAct = new QAction("New");
    newAct->setIcon(QIcon(":/pic/1.jpg"));
    newAct->setShortcut(QKeySequence::New);
    newAct->setStatusTip("new file");

    fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction(newAct);
    editMenu = menuBar()->addMenu("Edit");

    filetool = addToolBar("File"); //添加工具栏
    filetool->addAction(newAct);

    QStatusBar *status = statusBar();   //创建状态栏

    te = new QTextEdit;
    te->setMinimumSize(640,480);
    setCentralWidget(te);
}

MainWindow::~MainWindow()
{

}
