//
// Created by copewang on 2020/9/12.
//

#pragma once

#include <QString>
#include <QDebug>

#include <plog/Log.h>

namespace TaiShan {

void initLogger(const QString &logPath, const QString &logName);
QString LoggerDir();
QString LoggerName();
void resetCnvLogCount();

}

#define LOG_TO_FILE

#ifdef LOG_TO_FILE

#define LOG_I       PLOG_INFO
#define LOG_D       PLOG_DEBUG
#define LOG_W       PLOG_WARNING
#define LOG_E       PLOG_ERROR
#define LOG_F       PLOG_FATAL

#else

#define LOG         qDebug()
#define LOG_D       qDebug()
#define LOG_W       qDebug()
#define LOG_E       qDebug()
#define LOG_F       qDebug()
#endif
