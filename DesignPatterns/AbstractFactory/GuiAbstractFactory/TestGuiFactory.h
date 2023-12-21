//
// Created by 40611 on 2023/10/26.
//

#ifndef NEWTESTDEMO_TESTGUIFACTORY_H
#define NEWTESTDEMO_TESTGUIFACTORY_H

#include "GuiFactory.h"
#include "WindowsFactory.h"
#include "MacFactory.h"
#include <iostream>

using namespace std;

class TestGuiFactory {
public:
    void test(){
        // 根据不同的操作系统选择工厂
        GuiFactory* factory;
        std::string os = "Windows"; // 假设为Windows操作系统，实际中可根据实际情况选择
        if (os == "Windows") {
            factory = new WindowsFactory();
        } else if (os == "Mac") {
            factory = new MacFactory();
        } else {
            throw std::runtime_error("Unsupported operating system");
        }

        // 使用工厂创建GUI元素
        Button* button = factory->createButton();
        TextBox* textBox = factory->createTextBox();

        // 渲染GUI元素
        button->paint();
        textBox->paint();

        // 清理资源
        delete button;
        delete textBox;
        delete factory;

        return;
    }
};


#endif //NEWTESTDEMO_TESTGUIFACTORY_H
