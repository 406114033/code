//
// Created by 40611 on 2023/10/26.
//

#ifndef NEWTESTDEMO_MACFACTORY_H
#define NEWTESTDEMO_MACFACTORY_H

#include "GuiFactory.h"

// 具体工厂：Mac工厂
//具体工厂实现了抽象工厂声明的生成抽象产品的方法，生成一组具体产品，这些产品构成了一个mac产品族，每一个产品都位于某个产品等级结构中；
class MacFactory : public GuiFactory {
public:
    Button* createButton() override;

    TextBox* createTextBox() override;
};


#endif //NEWTESTDEMO_MACFACTORY_H
