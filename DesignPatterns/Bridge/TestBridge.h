//
// Created by 40611 on 2023/11/15.
//

#ifndef NEWTESTDEMO_TESTBRIDGE_H
#define NEWTESTDEMO_TESTBRIDGE_H

#pragma once
using namespace std;
#include <iostream>

// 实现类接口
class Color {
public:
    virtual void applyColor() = 0;
};
//具体实现类接口
class RedColor : public Color {
public:
    void applyColor() override {
        std::cout << "red color";
    }
};

class BlueColor : public Color {
public:
    void applyColor() override {
        std::cout << "blue color";
    }
};

// 抽象类
class Shape {
protected:
    Color* color;
public:
    Shape(Color* c) : color(c) {}
    virtual void applyColor() = 0;
};

//扩充抽象类

class Circle : public Shape {
public:
    Circle(Color* c) : Shape(c) {}
    void applyColor() override {
        std::cout << "Circle filled with ";
        color->applyColor();
        std::cout << "\n";
    }
};

class Square : public Shape {
public:
    Square(Color* c) : Shape(c) {}
    void applyColor() override {
        std::cout << "Square filled with ";
        color->applyColor();
        std::cout << "\n";
    }
};

class TestBridge {
public:
    TestBridge();
    void test();
    void testShapeColor();
};


#endif //NEWTESTDEMO_TESTBRIDGE_H
