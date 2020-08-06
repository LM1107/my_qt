#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //菜单栏
    QMenuBar *mBar = menuBar();

    //添加菜单
    QMenu *pFile = mBar->addMenu("文件");

    //添加菜单项，添加动作
    QAction *pnew = pFile->addAction("新建");

    pFile->addSeparator();  //添加分割线
    QAction *popen = pFile->addAction("打开");

    //工具栏 ， 菜单栏的快捷方式
    QToolBar *tb = addToolBar("toolBar");
    pb1 = new QPushButton;
    pb1->setIcon(QIcon(":/pic/1.png"));

    //添加小控件
    tb->addWidget(pb1);
    //工具栏添加快捷键
    //tb->addAction(pnew);

    //状态栏
    QStatusBar *sBar = statusBar();
    QLabel *l = new QLabel(this);
    l->setText("Normal text file add");
    sBar->addWidget(l);
    //addWidget 从左往右添加
    sBar->addWidget(new QLabel("2",this));
    sBar->addPermanentWidget(new QLabel("3",this));

    //核心控件
    QTextEdit *te = new QTextEdit(this);
    setCentralWidget(te);

    //浮动窗口
    QDockWidget *dock = new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea,dock);

    //给浮动窗口添加控件
    QTextEdit *te1 = new QTextEdit(this);
    dock->setWidget(te1);

    connect(pnew,SIGNAL(triggered(bool)),this,SLOT(actionTriggered()));
    connect(popen,SIGNAL(triggered(bool)),this,SLOT(actionTriggered()));
    connect(pb1,&QPushButton::clicked,this,
            [=]()
    {
        qDebug()<<"新建工具栏";
    }


            );

}

MainWindow::~MainWindow()
{

}

void MainWindow::actionTriggered()
{
    qDebug() << "被按下";
}
