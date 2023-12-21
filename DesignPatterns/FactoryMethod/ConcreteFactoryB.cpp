//
// Created by 40611 on 2023/10/31.
//

#include "ConcreteFactoryB.h"
#include "ConcreteProductB.h"


ConcreteFactoryB::ConcreteFactoryB() {

}

ConcreteFactoryB::~ConcreteFactoryB() {

}

Product *ConcreteFactoryB::createProduct() {
    return new ConcreteProductB();
}