//
// Created by 40611 on 2023/11/21.
//

#pragma once
#include <iostream>
using namespace std;

// 抽象基础组件接口
class TextComponent {
public:
    virtual void render() = 0;
};

// 具体文本组件，即基础组件
class ConcreteTextComponent : public TextComponent {
public:
    void render() override {
        std::cout << "Plain Text" ;
    }
};

// 抽象装饰器类
class TextDecorator : public TextComponent {
protected:
    TextComponent* component;

public:
    TextDecorator(TextComponent* component) : component(component) {}

    void render() override {
        component->render();
    }
};

// 具体装饰器类，用于添加粗体格式
class BoldTextDecorator : public TextDecorator {
public:
    BoldTextDecorator(TextComponent* component) : TextDecorator(component) {}

    void render() override {
        // 装饰额外的行为（加粗）
        std::cout << "<b>";
        TextDecorator::render();
        std::cout << "</b>";
    }
};

// 具体装饰器类，用于添加斜体格式
class ItalicTextDecorator : public TextDecorator {
public:
    ItalicTextDecorator(TextComponent* component) : TextDecorator(component) {}

    void render() override {
        // 装饰额外的行为（斜体）
        std::cout << "<i>";
        TextDecorator::render();
        std::cout << "</i>";
    }
};


class TestDecorator {
public:
    TestDecorator();
    void testDecorator();
    void transparentDecorator();    //透明装饰模式
    void translucencyDecorator();   //半透明装饰模式
};


