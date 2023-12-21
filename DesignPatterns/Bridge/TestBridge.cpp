//
// Created by 40611 on 2023/11/15.
//

#include "TestBridge.h"
#include "ConcreteImplementorA.h"
#include "ConcreteImplementorB.h"
#include "RefinedAbstraction.h"
#include "Abstraction.h"


TestBridge::TestBridge() {

}

void TestBridge::test() {
    cout << "Bridge pattern test" << endl;
    Implementor * pImp = new ConcreteImplementorA();
    Abstraction * pa = new RefinedAbstraction(pImp);
    pa->operation();

    Abstraction * pb = new RefinedAbstraction(new ConcreteImplementorB());
    pb->operation();

    delete pa;
    delete pb;
}

void TestBridge::testShapeColor() {
    cout << "testShape Color Bridge pattern test" << endl;
    Color* red = new RedColor();
    Color* blue = new BlueColor();

    Shape* circle = new Circle(red);
    Shape* square = new Square(blue);

    circle->applyColor();  //输出 Circle filled with red color
    square->applyColor();  //输出 Square filled with blue color

    delete red;
    delete blue;
    delete circle;
    delete square;
}
