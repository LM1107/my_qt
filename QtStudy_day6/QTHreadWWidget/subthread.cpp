#include "subthread.h"

subThread::subThread()
{

}

void subThread::run()
{
    while(1){
        qDebug() << "hello world";
        sleep(1);
    }
}
