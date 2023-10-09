//
// Created by 40611 on 2023/10/9.
//

#include "MultiThreadSyn.hpp"
#include <QDebug>
#include "Logger.hpp"

static int gNumber = 10;
#define CUSTOMER_NUM 10
sem_t sem;

MultiThreadSyn::MultiThreadSyn() {

}

MultiThreadSyn::~MultiThreadSyn() {

}

//------------Qt读写锁同步---------------


void ReadThread::run() {
    for (;;) {
       mRWLock.lockForRead();
        LOG_I << "Read Thread: " << QThread::currentThreadId() << ", Number is " << gNumber;
       mRWLock.unlock();
        if(gNumber >15) break;
        QThread::msleep(100);
    }
}

void WriteThread::run() {
    for (;;) {
        mRWLock.lockForRead();
        LOG_I << " gNumbre ++";
        gNumber++;
        mRWLock.unlock();
        if(gNumber >15) break;
        QThread::msleep(500);
    }
}

void MultiThreadSyn::readWriteLock() {
    WriteThread writeThread;
    writeThread.start();

// 创建并开启读线程
    ReadThread readThread[5];
    for (int i=0; i<5; ++i)
        readThread[i].start();

// 等待线程结束
    writeThread.wait();
    for (int i=0; i<5; ++i)
        readThread[i].wait();
}

//------------信号量同步---------------

void *get_server(void *thread_id) {
    int cusotmer_id = *((int *) thread_id);
    if (auto ret = sem_wait(&sem) == 0) {
        printf("ret =  %d\n", ret);
        printf("customer %d receive server ...\n", cusotmer_id);
        sem_post(&sem);
    }
    return nullptr;
}

void MultiThreadSyn::SemaphoreSyn() {
    sem_init(&sem, 0, 2);
    pthread_t customers[CUSTOMER_NUM];
    int customer_id[CUSTOMER_NUM];//用户id

    for (int index = 0; index < CUSTOMER_NUM; index++) {
        customer_id[index] = index;
        printf("customer %d arrived\n", customer_id[index]);
        int res = pthread_create(&customers[index], nullptr, get_server, &customer_id[index]);
        if (res) {
            printf("create thread error\n");
        }
    }
    for (int index = 0; index < CUSTOMER_NUM; index++) {
        pthread_join(customers[index], nullptr);
    }
    sem_destroy(&sem);
}

//------------条件变量同步---------------

pthread_cond_t qready = PTHREAD_COND_INITIALIZER;//初始构造条件变量
pthread_mutex_t qlock = PTHREAD_MUTEX_INITIALIZER;//初始构造锁

int x = 10, y = 20;

void *func1(void *arg) {
    qDebug() << "func1" << endl;
    pthread_mutex_lock(&qlock);
    while (x < y) {
        qDebug() << "wait 1" << endl;
        pthread_cond_wait(&qready, &qlock);
        qDebug() << "wait 2" << endl;
    }
    pthread_mutex_unlock(&qlock);
    qDebug() << "func1 end" << endl;
    return nullptr;
}

void *func2(void *arg) {
    qDebug() << "func2" << endl;
    pthread_mutex_lock(&qlock);
    x = 20, y = 10;
    qDebug() << "x & y changed" << endl;
    pthread_mutex_unlock(&qlock);
    if (x > y) {
        pthread_cond_signal(&qready);
    }
    qDebug() << "func2 end" << endl;
    return nullptr;
}

void MultiThreadSyn::conditionSyn() {
    pthread_t tid1, tid2;
    int res = pthread_create(&tid1, nullptr, func1, nullptr);
    if (res) {
        qDebug() << "pthread 1 create error" << endl;
    }
    _sleep(2);
    res = pthread_create(&tid2, nullptr, func2, nullptr);
    if (res) {
        qDebug() << "pthread 2 create error" << endl;
    }
    _sleep(10);

    void *retval;
    res = pthread_join(tid1, &retval);
    if (res) {
        printf("tid1=%d join error, res = %d\n", tid1, res);
    }
    printf("retval=%d\n", retval);
    res = pthread_join(tid2, &retval);
    if (res) {
        printf("tid1=%d join error, res = %d\n", tid2, res);
    }
    printf("retval=%d\n", retval);
}

//------------互斥锁同步---------------

pthread_mutex_t pthreadMutex = PTHREAD_MUTEX_INITIALIZER;
int gTotalTickerNum = 20;

void *sellTicket(void *arg) {
    for (int i = 0; i < 20; i++) {
        pthread_mutex_lock(&pthreadMutex);
        if (gTotalTickerNum > 0) {
            _sleep(1);
            printf("sell the %dth ticket\n", 20 - gTotalTickerNum + 1);
            gTotalTickerNum--;
        }
        pthread_mutex_unlock(&pthreadMutex);
    }
    return nullptr;
}

void MultiThreadSyn::mutexSyn() {
    pthread_t pthread[4];
    for (int index = 0; index < 4; index++) {
        int res = pthread_create(&pthread[index], nullptr, &sellTicket, nullptr);
        if (res) {
            printf("pthread create error, res=%d\n", res);
        }
    }
    _sleep(20);
    void *retval;
    for (int index = 0; index < 4; index++) {
        int res = pthread_join(pthread[index], &retval);
        if (res) {
            printf("tif=%d join error, res = %d\n", index, res);
        }
        printf("retval=%d\n", retval);
    }
}
