#include <QCoreApplication>
#include <QProcess>
#include <QDebug>
#include <QThread>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QProcess process;
    process.start("E:/qt_project/my_qt/QtStudy_day4/build-my_notepad-Desktop_Qt_5_9_1_MinGW_32bit-Debug/debug/my_notepad.exe");
/*
    QProcess process1;
    process1.start("E:/qt_project/my_qt/QtStudy_day5/build-paintEvent-Desktop_Qt_5_9_1_MinGW_32bit-Debug/debug/paintEvent.exe");
*/
    while(1){
        qDebug() << "hello world!";
        QThread::sleep(1);      //睡眠1秒
    }

    return a.exec();
}
