#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    filename = "";

    //添加菜单栏
    mBar = menuBar();

    QStringList list_mBar = {"File","Edit","Settings","About"};
    QStringList list_act = {"New","Open","Save","Undo","Copy","Paste","Font","color","widget","my_notepad","help","emailMe"};
    QStringList listp = {":/pic/1.jpg",":/pic/2.jpg",":/pic/3.jpg"};

    //添加菜单
    for(int i=0;i<4;i++)
    {
        menu[i] = mBar->addMenu(list_mBar.at(i));
        for(int j=0;j<3;j++)
        {
            //添加菜单项，添加动作
            Act[i][j] = new QAction(list_act.at(i*3+j));
            //Act[i][j] = menu[i]->addAction(list_act.at(i*3+j));
            Act[i][j]->setIcon(QIcon(listp.at(j)));
            menu[i]->addAction(Act[i][j]);
            menu[i]->addSeparator();
        }
    }

    Act[0][0]->setShortcut(QKeySequence::New);
    Act[0][0]->setStatusTip("New File");

    Act[0][1]->setShortcut(QKeySequence::Open);
    Act[0][1]->setStatusTip("open File");

    Act[0][2]->setShortcut(QKeySequence::Save);
    Act[0][2]->setStatusTip("save File");

    Act[1][0]->setShortcut(QKeySequence::Undo);
    Act[1][1]->setShortcut(QKeySequence::Copy);
    Act[1][2]->setShortcut(QKeySequence::Paste);


    //添加工具栏
//    pb1 = new QPushButton;
//    pb2 = new QPushButton;
//    pb3 = new QPushButton;

        filetool = addToolBar("File");
        filetool->addAction(Act[0][0]);
        filetool->addAction(Act[0][1]);
        filetool->addAction(Act[0][2]);
//    filetool->addWidget(pb1);
//    filetool->addWidget(pb2);
//    filetool->addWidget(pb3);

    te = new QTextEdit;
    te->setMinimumSize(640,480);
    setCentralWidget(te);   //设置中央窗口位置
    te->setReadOnly(true);

    connect(Act[0][0], SIGNAL(triggered(bool)), this, SLOT(newFile()));
    connect(Act[0][1], SIGNAL(triggered(bool)), this, SLOT(openFile()));
    connect(Act[0][2], SIGNAL(triggered(bool)), this, SLOT(saveFile()));

}

MainWindow::~MainWindow()
{

}

void MainWindow::newFile()
{
    /*
    qDebug() << "new File";

    QFile file("new.file");
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        qDebug() << "return new";
        return;
    }
    te->setReadOnly(false);
    //file.write(1);
    */
   int ret = QMessageBox::information(this,"信息","Do you want create a new file",QMessageBox::Yes, QMessageBox::No);
    switch (ret) {
    case QMessageBox::Yes:
        qDebug() << "choose yes to new file";
        te->setReadOnly(false);
        break;
    case QMessageBox::No:
        qDebug() << "choose no to new file";
        break;
    default:
        qDebug() << "should never be reached";
        break;
    }
    te->clear();
    filename = "";
    return;
}

void MainWindow::openFile()
{
    QString str = te->toPlainText();
    if(!str.isEmpty()){
        int ret = QMessageBox::question(this,"question","do you want to save?",QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel);
        switch (ret) {
        case QMessageBox::Save:
            saveFile();
            break;
        case QMessageBox::Discard:
            break;
        case QMessageBox::Cancel:
            return;
        }
    }
    QString name = QFileDialog::getOpenFileName(this,"open",".","text(*.txt *.cpp *.h)");
    if(name.isEmpty())
    {
        qDebug()<<"return open";
        return;
    }
    filename = name;
    QFile file(name);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) //只读打开文件
    {
        QMessageBox::warning(this,"warning","open file failed",QMessageBox::Ok);
        qDebug() << "return read";
        return;
    }
    while (!file.atEnd()) {  //判断是否读到文件末尾
        QByteArray line = file.readLine();   //读取文件一行内容
        te->append(line);
    }
    file.close();
}

void MainWindow::saveFile()
{
    //若没有文件则重新创建一个
    if(filename.isEmpty())
    {
        saveasFile();   //另存为
    }
    QFile file(filename);
    if(file.open(QIODevice::WriteOnly|QIODevice::Truncate|QIODevice::Text))
    {
        QMessageBox::warning(this,"warning","save file failed",QMessageBox::Ok);
        return;
    }
    QString str = te->toHtml();
    file.write(str.toStdString().c_str(),str.length());
    file.close();

}

void MainWindow::saveasFile()
{
    QString str = te->toHtml();
    QString name = QFileDialog::getSaveFileName(this,"saveas",".","text(*.txt *.cpp *.h)");
    if(name.isEmpty())
        return;
    filename = name;
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly|QIODevice::Truncate|QIODevice::Text))
    {
        QMessageBox::warning(this,"warning","saveas file failed",QMessageBox::Ok);
        return;
    }
    file.write(str.toStdString().c_str(),str.length());
    file.close();
}
