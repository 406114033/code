//
// Created by 40611 on 2023/6/27.
//

#include <QApplication>
#include "MainWindow.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(1280,720);
    w.show();

    return a.exec();
}