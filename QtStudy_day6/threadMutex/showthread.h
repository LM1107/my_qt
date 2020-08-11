#ifndef SHOWTHREAD_H
#define SHOWTHREAD_H

#include <QObject>
#include <QThread>
#include <iostream>
using namespace std;
#include <QMutex>
#include <QSemaphore>

extern int arr[10];
extern QMutex mutex;
extern QSemaphore sem1;
extern QSemaphore sem2;

class showThread : public QThread
{
public:
    showThread();
protected:
    void run();
};

#endif // SHOWTHREAD_H
