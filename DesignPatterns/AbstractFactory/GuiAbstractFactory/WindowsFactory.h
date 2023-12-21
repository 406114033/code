//
// Created by 40611 on 2023/10/26.
//

#ifndef NEWTESTDEMO_WINDOWSFACTORY_H
#define NEWTESTDEMO_WINDOWSFACTORY_H

#include "GuiFactory.h"
#include "Button.h"
#include "TextBox.h"

// 具体工厂：Windows工厂
//具体工厂实现了抽象工厂声明的生成抽象产品的方法，生成一组具体产品，这些产品构成了一个windows产品族，每一个产品都位于某个产品等级结构中；
class WindowsFactory : public GuiFactory {
public:
    Button* createButton() override;

    TextBox* createTextBox() override;
};


#endif //NEWTESTDEMO_WINDOWSFACTORY_H
