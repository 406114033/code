//
// Created by 40611 on 2023/6/27.
//
#pragma once
#include <QMainWindow>
#include "FirstThread.hpp"
#include "SecondThread.hpp"
#include <QSharedPointer>

class MainWindow : public QMainWindow
{
Q_OBJECT
public:
    explicit MainWindow();
    ~MainWindow();

protected slots:
    void startTask();

private:
    QSharedPointer<FirstThread> mFirstThread = nullptr;
    QSharedPointer<SecondThread> mSecondThread = nullptr;
};

