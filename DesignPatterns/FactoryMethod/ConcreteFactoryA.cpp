///////////////////////////////////////////////////////////
//  ConcreteFactoryA.cpp
//  Implementation of the Class ConcreteFactoryA
//  Created on:      02-十月-2014 10:18:58
//  Original author: colin
///////////////////////////////////////////////////////////

#include "ConcreteFactoryA.h"
#include "ConcreteProductA.h"


ConcreteFactoryA::ConcreteFactoryA() {

}


ConcreteFactoryA::~ConcreteFactoryA() {

}

Product *ConcreteFactoryA::createProduct() {

    return new ConcreteProductA();
}

