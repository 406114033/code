//
// Created by 40611 on 2023/7/10.
//

#include "FirstThread.hpp"
#include "QDebug"


FirstThread::FirstThread(QAudioDeviceInfo &device) : mAudioDevice(device) {

}

FirstThread::~FirstThread() {

}

void FirstThread::run() {
    qDebug() << "FirstThread start";
    qDebug() << "first main Thread  id = " << QThread::currentThreadId();
    for (;;) {

        if(isInterruptionRequested()) break;
        qDebug() << "first Thread  id = " << QThread::currentThreadId();
//        usleep(100);
        if(!mAudioDevice.isNull()){
            qDebug() << "FirstThread deviceName " << mAudioDevice.deviceName();
        }

    }
    qDebug() << "FirstThread end";
}


