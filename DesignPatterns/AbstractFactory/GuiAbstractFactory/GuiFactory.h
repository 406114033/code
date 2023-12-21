//
// Created by 40611 on 2023/10/26.
//

#ifndef NEWTESTDEMO_GUIFACTORY_H
#define NEWTESTDEMO_GUIFACTORY_H

#include "Button.h"
#include "TextBox.h"

//抽象工厂用于声明生成抽象产品的方法

class GuiFactory {
public:
    virtual Button* createButton() = 0;
    virtual TextBox* createTextBox() = 0;
};


#endif //NEWTESTDEMO_GUIFACTORY_H
