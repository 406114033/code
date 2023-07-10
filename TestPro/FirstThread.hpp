//
// Created by 40611 on 2023/7/10.
//
#pragma once
#include <QThread>
#include <QAudioDeviceInfo>

class FirstThread : public QThread{
Q_OBJECT
public:
    FirstThread(QAudioDeviceInfo &device);

    ~FirstThread();

protected:
    void run() override;
private:
    QAudioDeviceInfo mAudioDevice;
};

using FirstThreadPtr = QSharedPointer<FirstThread>;
