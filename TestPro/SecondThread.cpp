//
// Created by 40611 on 2023/7/10.
//

#include "SecondThread.hpp"
#include <QDebug>

SecondThread::SecondThread(QAudioDeviceInfo &device) : mAudioDevice(device) {

}

SecondThread::~SecondThread() {

}

void SecondThread::run() {
    qDebug() << "SecondThread start";
    qDebug() << "Second main Thread  id = " << QThread::currentThreadId();
    for (;;) {

        if(isInterruptionRequested()) break;
        qDebug() << "SecondThread id = " << QThread::currentThreadId();

//        usleep(100);
        if(!mAudioDevice.isNull()){
            qDebug() << "SecondThread deviceName " << mAudioDevice.deviceName();

        }

    }
    qDebug() << "SecondThread end";
}