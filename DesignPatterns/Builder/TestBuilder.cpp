//
// Created by 40611 on 2023/11/15.
//

#include "TestBuilder.h"
#include "ConcreteBuilder.h"
#include "Director.h"
#include "Builder.h"
#include "Product.h"

TestBuilder::TestBuilder() {

}

void TestBuilder::test() {
    ConcreteBuilder * builder = new ConcreteBuilder();
    Director  director;
    director.setBuilder(builder);
    Product * pd =  director.constuct();
    pd->show();

    delete builder;
    delete pd;
}
