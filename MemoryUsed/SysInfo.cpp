//
// Created by 40611 on 2023/6/27.
//

#include "SysInfo.hpp"
#include <QtGlobal>
#ifdef WIN32
#include "SysInfoWindowsImpl.hpp"
#endif

SysInfo &SysInfo::instance() {

#ifdef WIN32
    static SysInfoWindowsImpl singleton;
#elif defined(Q_OS_MAC)
    static SysInfoMacImpl singleton;
#elif defined(Q_OS_LINUX)
    static SysInfoLinuxImpl singleton;
#endif
    return singleton;

}

SysInfo::~SysInfo() {

}

SysInfo::SysInfo() {

}
