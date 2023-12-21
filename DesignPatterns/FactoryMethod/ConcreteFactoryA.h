

#include "Factory.h"

class ConcreteFactoryA : public Factory {

public:
    ConcreteFactoryA();

    virtual ~ConcreteFactoryA();

    virtual Product *createProduct();

};

