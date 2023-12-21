//
// Created by 40611 on 2023/10/31.
//

#include "TestFactoryMethod.h"
#include "Factory.h"
#include "ConcreteFactoryA.h"
#include "ConcreteFactoryB.h"
#include <iostream>
using namespace std;

TestFactoryMethod::TestFactoryMethod() {}

void TestFactoryMethod::test() {

    cout << " test FactoryMethod" << endl;
    // 使用工厂A创建产品A
    Factory *factoryA = new ConcreteFactoryA();
    Product *productA = factoryA->createProduct();
    productA->use();

    // 使用工厂B创建产品B
    Factory *factoryB = new ConcreteFactoryB();
    Product *productB = factoryB->createProduct();
    productB->use();

    delete factoryA;
    delete factoryB;
    delete productA;
    delete productB;
}