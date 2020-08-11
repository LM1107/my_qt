#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include "subthread.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    subThread *st = new subThread;
    st->start();

    while(1){
        qDebug() << "nihao!";
        QThread::sleep(1);
    }

    return a.exec();
}
