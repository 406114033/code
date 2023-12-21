//
// Created by 40611 on 2023/10/10.
//

#ifndef NEWTESTDEMO_SINGLETON_HPP
#define NEWTESTDEMO_SINGLETON_HPP

/*
在单例模式的实现过程中，需要注意如下三点：
1: 单例类的构造函数为私有；
2: 提供一个自身的静态私有成员变量；
3: 提供一个公有的静态工厂方法。
 */


class Singleton {
public:
    static Singleton* getInstance();
    void showMessage();
private:
    Singleton();
    static Singleton *instance;
};


#endif //NEWTESTDEMO_SINGLETON_HPP
