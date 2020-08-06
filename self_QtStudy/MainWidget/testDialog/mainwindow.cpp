#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *mBar = menuBar();
    setMenuBar(mBar);
    QMenu *menu = mBar->addMenu("对话框");
    QAction *p1 = menu->addAction("模态对话框");
    connect(p1,&QAction::triggered,this,
            [=]()
    {
        QDialog dlg;
        dlg.exec();
        qDebug()<<"1111";
    });
    QAction *p2 = menu->addAction("非模态对话框");
    connect(p2,&QAction::triggered,this,
            [=]()
    {
        QDialog *dlg = new QDialog;
        dlg->show();
        qDebug()<<"1111";
    });

    QAction *p3 = menu->addAction("标准模态对话框");
    connect(p3,&QAction::triggered,this,
            [=]()
    {
        QMessageBox::about(this,"about","关于qt");
    });

    QAction *p4 = menu->addAction("问题对话框");
    connect(p4,&QAction::triggered,this,
            [=]()
    {
        int ret = QMessageBox::question(this,"question","are u ok",\
                                        QMessageBox::Ok |\
                                        QMessageBox::Cancel);
        switch (ret) {
        case QMessageBox::Ok:
            qDebug()<<"i am ok";
            break;
        case QMessageBox::Cancel:
            qDebug()<<"i am not ok";
            break;
        default:
            break;
        }
    });

    QAction *p5 = menu->addAction("打开文件");
    connect(p5,&QAction::triggered,this,
            [=]()
    {
        QString path = QFileDialog::getOpenFileName(this,"open","../");
        qDebug()<<path;
    });

}

MainWindow::~MainWindow()
{

}
