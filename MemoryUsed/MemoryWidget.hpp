//
// Created by 40611 on 2023/6/27.
//

#ifndef NEWTESTDEMO_MEMORYWIDGET_HPP
#define NEWTESTDEMO_MEMORYWIDGET_HPP


#include <QtCharts/QLineSeries>
#include "SysInfoWidget.hpp"
class MemoryWidget : public SysInfoWidget
{
Q_OBJECT
public:
    explicit MemoryWidget(QWidget *parent = 0);

protected slots:
    void updateSeries() override;
    //以曲线图动态显示内存的占用率
private:
    QtCharts::QLineSeries* mSeries;
    qint64 mPointPositionX;
};


#endif //NEWTESTDEMO_MEMORYWIDGET_HPP
