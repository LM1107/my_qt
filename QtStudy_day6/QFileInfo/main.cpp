#include <QCoreApplication>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>
#include <QDir>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile file("1.txt");
    QFileInfo finfo(file);

    if(!finfo.exists()){
        qDebug() << "file not exist!";
        return -1;
    }else{
        qDebug() << "file exist!";
    }

    qDebug() << finfo.fileName();
    qDebug() << finfo.suffix();
    QDir dir = finfo.absoluteDir();
    qDebug() << dir.dirName();
    qDebug() << finfo.absoluteFilePath();
    qDebug() << finfo.created().toString("yyyy-MM-dd hh:mm:ss A dddd");

    //设置过滤器
    dir.setFilter(QDir::Files|QDir::Hidden|QDir::NoSymLinks);
    dir.setSorting(QDir::Size|QDir::Reversed);

    QFileInfoList list = dir.entryInfoList();
    std::cout << " Byte filenames" << std::endl;
    for(int i=0;i<list.size();++i){
        QFileInfo fileInfo = list.at(i);
        std::cout << qPrintable(QString("%1 %2").arg(fileInfo.size(),10).arg(fileInfo.fileName()));
        std::cout << std::endl;
    }

    qDebug() << dir.dirName();
    dir.cd("..");
    qDebug() << dir.dirName();
    return a.exec();
}
