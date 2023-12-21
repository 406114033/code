//
// Created by 40611 on 2023/10/31.
//

#ifndef NEWTESTDEMO_CONCRETEPRODUCTB_H
#define NEWTESTDEMO_CONCRETEPRODUCTB_H

#include "Product.h"


class ConcreteProductB : public Product {

public:
    ConcreteProductB();

    virtual ~ConcreteProductB();

    virtual void use();


};


#endif //NEWTESTDEMO_CONCRETEPRODUCTB_H
