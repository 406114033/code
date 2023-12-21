//
// Created by 40611 on 2023/10/26.
//

#ifndef NEWTESTDEMO_TEXTBOX_H
#define NEWTESTDEMO_TEXTBOX_H


// 抽象产品：文本框
//抽象产品为每种产品声明接口，在抽象产品中定义了产品的抽象业务方法；
class TextBox {
public:
    virtual void paint() = 0;
};

#endif //NEWTESTDEMO_TEXTBOX_H
