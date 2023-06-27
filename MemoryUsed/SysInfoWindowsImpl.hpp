//
// Created by 40611 on 2023/6/27.
//

#ifndef NEWTESTDEMO_SYSINFOWINDOWSIMPL_HPP
#define NEWTESTDEMO_SYSINFOWINDOWSIMPL_HPP

#include "SysInfo.hpp"
#include <QtGlobal>
#include <QVector>
typedef struct _FILETIME FILETIME;
class SysInfoWindowsImpl : public SysInfo{
public:
    SysInfoWindowsImpl();
    void init() override;
    //windows下的实现
    double cpuLoadAverage() override;

    //windows下的实现
    double memoryUsed() override;
private:
    //获取并记录CPU的原始数据
    QVector<qulonglong> cpuRawData();
    //转换时间格式
    qulonglong convertFileTime(const FILETIME& filetime) const;
private:
    QVector<qulonglong> mCpuLoadLastValues;

};


#endif //NEWTESTDEMO_SYSINFOWINDOWSIMPL_HPP
