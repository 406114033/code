#include <iostream>
using namespace std;
#include <vector>
//#include "Logger.hpp"
#include "dbg.h"
//#include "Windows.h"
#include <QImage>
#include <QStorageInfo>
#include <QDebug>
#include <QApplication>
#include "testui.h"

void print(int j,std::string const& s){
    for (int i = 0; i < 10000; ++i) {
        std::cout << " i = "<< i << " " << s <<  std::endl;
    }
}

void oops(int someParam){
    char buffer[1024];
    sprintf(buffer,"i%",someParam);
    int n = 10;
    std::thread t(print,n,buffer);
    t.detach();
}


int main(int argc,char*argv[]){

//    QStorageInfo storageInfo("D:\\MP4\\enhance_output\\dstImg4.png");  //windows下 为操作系统安装目录
////    storageInfo.setPath("D:\\MP4\\enhance_output\\dstImg4.png");
//    qDebug() << storageInfo.rootPath();
//    qDebug() << "device" << storageInfo.device();
//    if(storageInfo.isReadOnly())
//        qDebug() << "sReadOnly: " << storageInfo.isReadOnly();
//    qDebug() << "name:" << storageInfo.name();
//    qDebug() << "fileSystemType:" << storageInfo.fileSystemType();
//    qDebug() << "size:" << storageInfo.bytesTotal()/1024/1024/1024 << "G";
//    qDebug() << "availableSize:" << storageInfo.bytesAvailable()/1024/1024/1024 << "G";

//    int& i = 42;
//    int const& i = 42;
//    QApplication a(argc,argv);
//    TestUI w;
//    w.show();

    oops(100);
    return 0;
}