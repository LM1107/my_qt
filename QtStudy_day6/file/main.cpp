#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include <string.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile file("1.txt");
    if(file.exists())
        qDebug() << "file exists!";
    else{
        qDebug() << "file not exists!";
        //return -1;
    }
    if(!file.open(QIODevice::ReadWrite|QIODevice::Text))
    {
        qDebug() << file.errorString();
        return -1;
    }

    char buf[100] = "hello Qt 123";
    file.write(buf,strlen(buf));
    file.flush();

    file.seek(0);
    while(!file.atEnd())
    {
        QByteArray arr = file.readAll();
        qDebug() << arr;
    }

    file.close();

    return a.exec();
}
