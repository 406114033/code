//
// Created by 40611 on 2023/6/27.
//

#ifndef NEWTESTDEMO_SYSINFO_HPP
#define NEWTESTDEMO_SYSINFO_HPP


class SysInfo {
public:
    //构造和系统函数
    static SysInfo& instance();
    virtual ~SysInfo();

    //初始化函数
    virtual void init() = 0;

    //cpu平均使用率
    virtual double cpuLoadAverage() = 0;

    //内存使用率
    virtual double memoryUsed() = 0;

protected:
    explicit SysInfo();
private:
    SysInfo(const SysInfo& rhs);
    SysInfo& operator=(const SysInfo& rhs);

};

#endif //NEWTESTDEMO_SYSINFO_HPP
