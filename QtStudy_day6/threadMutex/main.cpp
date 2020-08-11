#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <iostream>
using namespace std;
#include "showthread.h"
#include <QMutex>
#include <QSemaphore>

int arr[10] = {1,2,3,4,5,6,7,8,9,10};
QMutex mutex;   //初始化一把锁
QSemaphore sem1(1);     //生产者的信号量:可生产
QSemaphore sem2(0);     //消费者的信号量:不可消费

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    showThread *st = new showThread;
    st->start();

    while(1){
//        mutex.lock();   //上锁
        sem2.acquire();
        for(int i=9;i>=0;i--)
            cout<<arr[i];
        cout<<endl;
//        mutex.unlock();
        sem1.release();
        QThread::sleep(1);
    }

    return a.exec();
}
