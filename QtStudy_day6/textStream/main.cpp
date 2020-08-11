#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QDataStream>

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
/*
    QFile file("1.txt");
    if(!file.open(QIODevice::WriteOnly|QIODevice::Truncate|QIODevice::Text))
    {
        qDebug()<<file.errorString();
        return -1;
    }
    QTextStream out(&file);
    out<<"hello world";        //向文件中写入数据
    file.close();

    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        qDebug()<<file.errorString();
        return -1;
    }
    QTextStream in(&file);
    while(!in.atEnd())
    {
        qDebug() << in.readAll();
    }
    file.close();
*/
    QFile file("1.txt");
    if(!file.open(QIODevice::ReadWrite|QIODevice::Text))
        {
        qDebug() << file.errorString();
                    return -1;
    }
    QDataStream out(&file);
    out<<QString("helloworld")<<quint32(123)<<QChar('H')<<double(12.123);
    file.seek(0);

    QString str;
    quint32 b;
    QChar c;
    double d;
    out >> str>>b>>c>>d;
    qDebug()<<str<<b<<c<<d;

    return a.exec();
}
