//
// Created by 40611 on 2023/6/27.
//

#include "CpuWidget.hpp"

#include "SysInfo.hpp"
using namespace QtCharts;
CpuWidget::CpuWidget(QWidget* parent) :
        SysInfoWidget(parent),
        mSeries(new QPieSeries(this))
{
    //以饼状图显示CPU的使用率
    mSeries->setHoleSize(0.35);
    mSeries->append("CPU Load", 30.0);
    mSeries->append("CPU Free", 70.0);

    QChart* chart = chartView().chart();
    chart->addSeries(mSeries);
    chart->setTitle("CPU average load");
}
void CpuWidget::updateSeries()
{
    //动态刷新CPU的使用率
    double cpuLoadAverage = SysInfo::instance().cpuLoadAverage();
    mSeries->clear();
    mSeries->append("Load", cpuLoadAverage);
    mSeries->append("Free", 100.0 - cpuLoadAverage);
}