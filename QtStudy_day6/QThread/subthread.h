#ifndef SUBTHREAD_H
#define SUBTHREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>

class subThread : public QThread
{
    Q_OBJECT
public:
    subThread();
protected:
    void run();
};

#endif // SUBTHREAD_H
