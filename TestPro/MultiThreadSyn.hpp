//
// Created by 40611 on 2023/10/9.
//

#ifndef NEWTESTDEMO_MULTITHREADSYN_HPP
#define NEWTESTDEMO_MULTITHREADSYN_HPP
//--------多线程同步
#include <QThread>
#include <QReadWriteLock>
#include <QObject>
#include "pthread.h"
#include <semaphore.h>

class ReadThread : public QThread{
Q_OBJECT
public:

protected:
    void run() override;

private:
    QReadWriteLock mRWLock;
};

class WriteThread : public QThread{
Q_OBJECT
public:

protected:
    void run() override;
private:
    QReadWriteLock mRWLock;
};

class MultiThreadSyn : public QObject{
    Q_OBJECT
public:
    MultiThreadSyn();
    ~MultiThreadSyn();
    void readWriteLock();  //读写锁
    void SemaphoreSyn();   //信号量
    void conditionSyn();   //条件变量
    void mutexSyn();       //互斥锁

};


#endif //NEWTESTDEMO_MULTITHREADSYN_HPP
