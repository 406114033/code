//
// Created by 40611 on 2023/6/27.
//

#ifndef NEWTESTDEMO_CPUWIDGET_HPP
#define NEWTESTDEMO_CPUWIDGET_HPP

#include <QtCharts/QPieSeries>
#include "SysInfoWidget.hpp"
class CpuWidget : public SysInfoWidget
{
Q_OBJECT
public:
    explicit CpuWidget(QWidget* parent = 0);
protected slots:
    void updateSeries() override;
private:
    QtCharts::QPieSeries* mSeries;
};


#endif //NEWTESTDEMO_CPUWIDGET_HPP
