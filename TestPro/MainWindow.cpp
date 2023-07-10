//
// Created by 40611 on 2023/6/27.
//

#include "MainWindow.hpp"
#include <QDebug>
#include <QVBoxLayout>
#include <QPushButton>
#include <QAudioDeviceInfo>

MainWindow::MainWindow()
{
    setCentralWidget(new QWidget());
    auto mainLayout = new QHBoxLayout(centralWidget());
    auto btn = new QPushButton("start");
    mainLayout->addWidget(btn);
#if 0
    connect(btn, &QPushButton::clicked,[=](){
        startTask();
    });
#else
    connect(btn, &QPushButton::clicked, this,&MainWindow::startTask);
#endif

}

MainWindow::~MainWindow()
{
    if(mFirstThread){
        if(mFirstThread->isRunning()){
            mFirstThread->requestInterruption();
        }
    }
    if(mSecondThread){
        if(mSecondThread->isRunning()){
            mSecondThread->requestInterruption();
        }
    }
}

void MainWindow::startTask() {
    qDebug() << " main Thread id = " << QThread::currentThreadId();
    auto device = QAudioDeviceInfo::defaultInputDevice();
    if(!mFirstThread){
        mFirstThread.reset(new FirstThread(device));
    }
    if(!mSecondThread){
        mSecondThread.reset(new SecondThread(device));
    }
    mFirstThread->start();
    mSecondThread->start();

}