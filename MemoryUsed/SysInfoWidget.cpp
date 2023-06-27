//
// Created by 40611 on 2023/6/27.
//

#include "SysInfoWidget.hpp"

#include <QVBoxLayout>
using namespace QtCharts;
SysInfoWidget::SysInfoWidget(QWidget *parent,
                             int startDelayMs,
                             int updateSeriesDelayMs) :
        QWidget(parent),
        mChartView(this)
{
    //初始化定时器和控件基本样式
    mRefreshTimer.setInterval(updateSeriesDelayMs);
    connect(&mRefreshTimer, &QTimer::timeout,
            this, &SysInfoWidget::updateSeries);
    QTimer::singleShot(startDelayMs, [this] { mRefreshTimer.start(); });

    mChartView.setRenderHint(QPainter::Antialiasing);
    mChartView.chart()->legend()->setVisible(false);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(&mChartView);
    setLayout(layout);
}
QChartView& SysInfoWidget::chartView()
{
    return mChartView;
}