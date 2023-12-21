//
// Created by 40611 on 2023/11/22.
//

#include "TestStrategy.h"
#include "Context.h"
#include "ConcreteStrategyA.h"
#include "ConcreteStrategyB.h"
#include "Strategy.h"

TestStrategy::TestStrategy() {

}

//策略模式
void TestStrategy::test01() {
    Strategy * s1 = new ConcreteStrategyA();
    Context * cxt = new Context();
    cxt->setStrategy(s1);
    cxt->algorithm();

    Strategy *s2 = new ConcreteStrategyB();
    cxt->setStrategy(s2);
    cxt->algorithm();

    delete s1;
    delete s2;
    delete cxt;
}

//策略模式+简单工厂
void TestStrategy::test02() {

    Context * cxt1 = new Context('A');
    cxt1->algorithm();

    Context * cxt2 = new Context('B');
    cxt2->algorithm();

    delete cxt1;
    delete cxt2;

}