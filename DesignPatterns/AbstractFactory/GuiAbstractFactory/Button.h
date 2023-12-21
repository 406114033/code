//
// Created by 40611 on 2023/10/26.
//

#ifndef NEWTESTDEMO_BUTTON_H
#define NEWTESTDEMO_BUTTON_H


// 抽象产品：按钮
//抽象产品为每种产品声明接口，在抽象产品中定义了产品的抽象业务方法；
class Button {
public:
    virtual void paint() = 0;
};


#endif //NEWTESTDEMO_BUTTON_H
