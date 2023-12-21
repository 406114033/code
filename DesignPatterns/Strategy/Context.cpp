///////////////////////////////////////////////////////////
//  Context.cpp
//  Implementation of the Class Context
//  Created on:      09-十月-2014 22:21:07
//  Original author: colin
///////////////////////////////////////////////////////////

#include "Context.h"
#include "ConcreteStrategyA.h"
#include "ConcreteStrategyB.h"

Context::Context(){
}

Context::~Context(){
}

void Context::algorithm(){
	m_pStrategy->algorithm();
}

void Context::setStrategy(Strategy* st){
	m_pStrategy = st;
}

Context::Context(char type) {
    switch (type) {
        case 'A':
            m_pStrategy = new ConcreteStrategyA();
            break;
        case 'B':
            m_pStrategy = new ConcreteStrategyB();
            break;
        default:
            break;
    }
}

