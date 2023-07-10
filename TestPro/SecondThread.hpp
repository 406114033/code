//
// Created by 40611 on 2023/7/10.
//

#pragma once
#include <QThread>
#include <QSharedPointer>
#include "QAudioDeviceInfo"

class SecondThread : public QThread{
    Q_OBJECT
public:
    SecondThread(QAudioDeviceInfo &device);

    ~SecondThread();

protected:
    void run() override;

private:
    QAudioDeviceInfo mAudioDevice;
};

using SecondThreadPtr = QSharedPointer<SecondThread>;


