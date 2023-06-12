//
// Created by copewang on 2020/9/12.
//

#include "Logger.hpp"
#include <plog/Log.h> // Step1: include the headers
#include <plog/Appenders/ColorConsoleAppender.h>
#include <plog/Formatters/FuncMessageFormatter.h>
#include <QStandardPaths>
#include <QDir>
#include <QDebug>
#include <QApplication>
#include <QFileInfo>
#include <QTime>
#include "IpcDefine.hpp"

namespace TaiShan {

static QString gsLoggerDir;// 日志所在路径
static QString dstLogName; //日志名称

static QString appName() {
    return QFileInfo(QCoreApplication::applicationFilePath()).baseName();
}


static QString appendPath(const QString &path, const QString &component) {
    return QDir::cleanPath(path + QDir::separator() + component);
}

// 系统Cache文件夹路径
static QString appCacheDir() {
    auto cacheDir = QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation);
    if (!QDir().exists(cacheDir)) {
        QDir().mkpath(cacheDir);
    }
    return cacheDir;
}

// 默认的日志路径
static QString appLogDir() {
    auto dirPath = appendPath(appCacheDir(), "log");
    dirPath = appendPath(dirPath, "Player");
    dirPath = appendPath(dirPath, appName());
    if (!QDir().exists(dirPath)) {
        QDir().mkpath(dirPath);
    }

    return dirPath;
}

// 多出限制的数目，删除
static void setLogFileCount(int size, QString dir) {
    //--size; 保留size个日志
    QStringList files = QDir(dir).entryList(QDir::NoFilter, QDir::Time);
    const int fileCount = files.size();
    if ((fileCount - 2) == size) {
        return;
    }

    for (int i = fileCount - 1; i > -1; --i) {
        if ((files.size() - 2) > size) {
            if (files[i] != "." && files[i] != "..") {
                QFile(dir + QDir::separator() + files[i]).remove();
                files.removeAt(i);
            }
        } else {
            break;
        }
    }
}

// 创建日志文件
static void init(const QString &path, const QString &logName, const int fileSize) {
    auto logDir = path;
    dstLogName = logName;
    if (path.isEmpty()) {
        logDir = appLogDir();
    }
    if (!QDir().exists(logDir)) {
        QDir().mkpath(logDir);
    }
    gsLoggerDir = logDir;

    if (dstLogName.isEmpty()) {
        dstLogName = "log";
    }
    auto logPath = appendPath(logDir, dstLogName).append(
            QDateTime::currentDateTime().toString("_yyyy_MM_dd_hh_mm_ss")).append(".txt");

    static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
#ifdef _WIN32
    auto &&ss = logPath.toStdWString();
    static plog::RollingFileAppender<plog::TxtFormatter> fileAppender(ss.c_str(), 5 * 1024 * 1024,
                                                                      1); // 每次使用时日志文件数量(5M)及体积限制
#else
    auto &&ss = logPath.toLocal8Bit(); // utf8在中文目录下无法写入
    static plog::RollingFileAppender<plog::TxtFormatter> fileAppender(ss.constData(), 5 * 1024 * 1024,
                                                                      1); // 每次使用时日志文件数量(5M)及体积限制
#endif
    qDebug() << "initLogger Path: " << logPath;

    plog::init(plog::verbose, &fileAppender).addAppender(&consoleAppender);

    setLogFileCount(fileSize, logDir); // 日志文件总数量限制
    resetCnvLogCount();// 转换日志限制

    LOG_I << "---taiShan--- initLogger, log file path: " << logPath;
}


// 只提供日志路径，日志名字固定
/*void initLogger(const QString &logPath) {
    init(logPath, "TaiShan_Log", 3);
}*/


// 提供日志路径和名字
void initLogger(const QString &logPath, const QString &logName) {
    init(logPath, logName, 5);
}


// 返回日志所在路径
QString LoggerDir() {
    return gsLoggerDir;
}


// 限制转换日志数目，多出删除
void resetCnvLogCount() {
    setLogFileCount(CNV_LOGS_MAX, (gsLoggerDir + QDir::separator() + CNV_FOLDER));
}

QString LoggerName() {
    return dstLogName;
}

}
