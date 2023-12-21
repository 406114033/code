//
// Created by 40611 on 2023/10/31.
//

#include "TestSimpleFactory.h"
#include "Factory.h"
#include <iostream>


TestSimpleFactory::TestSimpleFactory() {}

void TestSimpleFactory::test() {
    cout << " test SimpleFactory" << endl;

    Product * prod = Factory::createProduct("A");

    prod->Use();

    delete prod;
}
