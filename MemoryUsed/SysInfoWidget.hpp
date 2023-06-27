//
// Created by 40611 on 2023/6/27.
//

#ifndef NEWTESTDEMO_SYSINFOWIDGET_HPP
#define NEWTESTDEMO_SYSINFOWIDGET_HPP


#include <QWidget>
#include <QTimer>
#include <QtCharts/QChartView>

class SysInfoWidget : public QWidget
{
Q_OBJECT
public:
    //@1父控件 @2控件延时 @3控件的刷新事件
    explicit SysInfoWidget(QWidget *parent = 0,
                           int startDelayMs = 500,
                           int updateSeriesDelayMs = 500);
protected:
    //获取公共的QtCharView控件
    QtCharts::QChartView& chartView();
protected slots:
    //刷新控件
    virtual void updateSeries() = 0;
private:
    QTimer mRefreshTimer;
    QtCharts::QChartView mChartView;
};



#endif //NEWTESTDEMO_SYSINFOWIDGET_HPP
