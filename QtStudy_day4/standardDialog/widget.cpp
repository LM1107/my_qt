#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    pb_file = new QPushButton("File");
    pb_color = new QPushButton("Color");
    pb_msg = new QPushButton("Message");
    pb_input = new QPushButton("Input");
    pb_font = new QPushButton("Font");

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(pb_file);
    vbox->addWidget(pb_msg);
    vbox->addWidget(pb_input);
    vbox->addWidget(pb_color);
    vbox->addWidget(pb_font);

    te = new QTextEdit("Hello Qt:");
    te->setMinimumSize(640,480);

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addLayout(vbox);
    hbox->addWidget(te);
    setLayout(hbox);

    connect(pb_file,SIGNAL(clicked(bool)),this,SLOT(openFile()));
    connect(pb_msg,SIGNAL(clicked(bool)),this,SLOT(showMsg()));
    connect(pb_input,SIGNAL(clicked(bool)),this,SLOT(inputData()));
    connect(pb_color,SIGNAL(clicked(bool)),this,SLOT(choseColor()));
    connect(pb_font,SIGNAL(clicked(bool)),this,SLOT(choseFont()));

}

Widget::~Widget()
{

}

void Widget::openFile()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open",".","Image(*.txt *.h *.cpp)");
    if(filename.isEmpty())
            return;
    te->setText(filename);

    QFile file("filename");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))     //只读打开文件
    {
        qDebug()<<"return ";
        return;
    }
//    qDebug()<<"starting read file";
    while(!file.atEnd()){  //判断是否读到末尾
        QByteArray line = file.readLine();  //读取文件一行内容
//        qDebug()<<"starting read file";
        te->append(line);
    }
    file.close();
}

void Widget::showMsg()
{
    int ret = QMessageBox::information(this,"信息","r u sure?",QMessageBox::Yes|QMessageBox::No);
    switch (ret) {
      case QMessageBox::Yes:
          qDebug()<< "Save was clicked";
          break;
      case QMessageBox::No:
          qDebug()<<"Don't Save was clicked";
          break;
      default:
          qDebug()<<"should never be reached";
          break;
    }
    /*
    QMessageBox msgBox;
    msgBox.setText("The document has been modified.");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setButtonText(QMessageBox::Discard,"Not Save");
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    switch (ret) {
      case QMessageBox::Save:
          qDebug()<< "Save was clicked";
          break;
      case QMessageBox::Discard:
          qDebug()<<"Don't Save was clicked";
          break;
      case QMessageBox::Cancel:
          qDebug()<<"Cancel was clicked";
          break;
      default:
          qDebug()<<"should never be reached";
          break;
    }
    */
}

void Widget::inputData()
{

}

void Widget::choseColor()
{

}

void Widget::choseFont()
{

}
