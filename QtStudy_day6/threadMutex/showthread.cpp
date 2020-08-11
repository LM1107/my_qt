#include "showthread.h"

showThread::showThread()
{

}

void showThread::run()
{
    while(1)
    {
//        mutex.lock();
        sem1.acquire();
        for(int i=0;i<10;i++)
        {
            cout << arr[i];
        }
        cout << endl;
//        mutex.unlock();
        sem2.release();
        sleep(1);
    }
}
