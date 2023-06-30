//
// Created by 40611 on 2023/6/27.
//

#ifndef NEWTESTDEMO_MAINWINDOW_HPP
#define NEWTESTDEMO_MAINWINDOW_HPP


#include <QMainWindow>
#include "CpuWidget.hpp"
#include "MemoryWidget.hpp"
class MainWindow : public QMainWindow
{
Q_OBJECT
public:
    explicit MainWindow();
    ~MainWindow();
private:
    CpuWidget* mCpuWidget = nullptr;
    MemoryWidget* mMemoryWidget = nullptr;
};


#endif //NEWTESTDEMO_MAINWINDOW_HPP
