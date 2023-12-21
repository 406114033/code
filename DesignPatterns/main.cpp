//
// Created by 40611 on 2023/10/10.
//

#include <iostream>
using namespace std;
#include "Singleton.hpp"
#include <vector>
//#include "AbstractFactory/AbstractFactory.h"
//#include "AbstractFactory/ConcreteFactory1.h"
//#include "AbstractFactory/ConcreteFactory2.h"
//#include "AbstractFactory/GuiAbstractFactory/TestGuiFactory.h"
//#include "SimpleFactory/TestSimpleFactory.h"
//#include "FactoryMethod/TestFactoryMethod.h"
//#include "Bridge/TestBridge.h"
//#include "Adapter/TestAdapter.h"
//#include "Builder/TestBuilder.h"
//#include "Facade/TestFacade.h"
//#include "Decorator/TestDecorator.h"
//#include "Obeserver/TestObeserver.h"
#include "Strategy/TestStrategy.h"


int main(int argc, char **argv) {

//-----------------单例模式--------------------------
//    Singleton::getInstance()->showMessage();

//-----------------简单工厂模式--------------------
//    TestSimpleFactory testSimpleFactory;
//    testSimpleFactory.test();

//-----------------工厂方法模式-----------------------

//    TestFactoryMethod testFactoryMethod;
//    testFactoryMethod.test();

//-----------------抽象工厂模式-----------------------
//    AbstractFactory * fc = new ConcreteFactory1();
//    AbstractProductA * pa =  fc->createProductA();
//    AbstractProductB * pb = fc->createProductB();
//    pa->use();
//    pb->eat();
//
//    AbstractFactory * fc2 = new ConcreteFactory2();
//    AbstractProductA * pa2 =  fc2->createProductA();
//    AbstractProductB * pb2 = fc2->createProductB();
//    pa2->use();
//    pb2->eat();
//
//    delete fc;
//    delete pa;
//    delete pb;
//    delete fc2;
//    delete pa2;
//    delete pb2;
//
//    TestGuiFactory testGuiFactory;
//    testGuiFactory.test();

//-----------------桥接模式---------------
//    TestBridge testBridge;
//    testBridge.test();
//    testBridge.testShapeColor();

//-----------------适配器式---------------
//    TestAdapter testAdapter;模
//    testAdapter.test();

//-----------------建造者模式---------------
//    TestBuilder testBuilder;
//    testBuilder.test();

//-----------------外观模式---------------
//    TestFacade testFacade;
//    testFacade.testFacadePattern();

//-----------------装饰模式---------------
//    TestDecorator testDecorator;
//    testDecorator.testDecorator();
//    testDecorator.transparentDecorator();
//    testDecorator.translucencyDecorator();

//-----------------观察者模式---------------
//    TestObeserver testObeserver;
//    testObeserver.test();

//-----------------策略模式---------------
    TestStrategy testStrategy;
    testStrategy.test01();
    testStrategy.test02();

    return 0;
}