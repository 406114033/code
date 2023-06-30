//
// Created by 40611 on 2023/6/27.
//

#include "MainWindow.hpp"
#include <QDebug>
#include "SysInfo.hpp"
#include <QVBoxLayout>

MainWindow::MainWindow()
{
    setCentralWidget(new QWidget());
    auto mainLayout = new QHBoxLayout(centralWidget());
    mCpuWidget = new CpuWidget(this);
    mMemoryWidget = new MemoryWidget(this);
    mainLayout->addWidget(mCpuWidget);
    mainLayout->addWidget(mMemoryWidget);
    SysInfo::instance().init();

}
MainWindow::~MainWindow()
{   if(mCpuWidget){
        delete mCpuWidget;
        mCpuWidget = nullptr;
    }
    if(mMemoryWidget){
        delete mMemoryWidget;
        mMemoryWidget = nullptr;
    }
}