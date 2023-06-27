//
// Created by 40611 on 2023/6/27.
//

#include "MainWindow.hpp"
#include <QDebug>
#include "SysInfo.hpp"
#include <QVBoxLayout>

MainWindow::MainWindow()
{
    QVBoxLayout layout;
    layout.setParent(this);
    layout.addWidget(&mCpuWidget);
    layout.addWidget(&mMemoryWidget);
    SysInfo::instance().init();
}
MainWindow::~MainWindow()
{
}