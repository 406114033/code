//
// Created by 40611 on 2023/10/26.
//

#ifndef NEWTESTDEMO_WINDOWSBUTTON_H
#define NEWTESTDEMO_WINDOWSBUTTON_H

#include "Button.h"
#include <iostream>
using namespace std;


// 具体产品：Windows按钮
//具体产品定义具体工厂生产的具体产品对象，实现抽象产品接口中定义的业务方法。
class WindowsButton : public Button {
public:
    void paint() override;
};


#endif //NEWTESTDEMO_WINDOWSBUTTON_H
