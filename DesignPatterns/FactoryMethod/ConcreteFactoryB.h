//
// Created by 40611 on 2023/10/31.
//

#ifndef NEWTESTDEMO_CONCRETEFACTORYB_H
#define NEWTESTDEMO_CONCRETEFACTORYB_H

#include "Factory.h"


class ConcreteFactoryB : public Factory {

public:
    ConcreteFactoryB();

    virtual ~ConcreteFactoryB();

    virtual Product *createProduct();


};


#endif //NEWTESTDEMO_CONCRETEFACTORYB_H
