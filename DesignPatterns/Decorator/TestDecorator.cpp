//
// Created by 40611 on 2023/11/21.
//

#include "TestDecorator.h"
#include "ConcreteComponent.h"
#include "ConcreteDecoratorA.h"
#include "ConcreteDecoratorB.h"
#include "Component.h"

TestDecorator::TestDecorator() {

}

void TestDecorator::testDecorator() {
    ConcreteComponent * pRealProd = new ConcreteComponent();
    //动态增加行为
    Component * pA = new ConcreteDecoratorA(pRealProd);
    pA->operation();
//输出
//	 ConcreteComponent's normal operation!
//	 addBehavior AAAA

    //继续动态增加行为
    Component * pB = new ConcreteDecoratorB(pA);
    pB->operation();
//输出
//    ConcreteComponent's normal operation!
//    addBehavior AAAA
//    addBehavior BBBB

    delete pRealProd;
    delete pA;
    delete pB;
}

void TestDecorator::transparentDecorator() {
    TextComponent* text = new ConcreteTextComponent();

    TextComponent* boldText = new BoldTextDecorator(text);

    TextComponent* boldItalicText = new ItalicTextDecorator(boldText);

    // 渲染文本
    text->render(); // 输出：Plain Text
    std::cout << std::endl;

    boldText->render(); // 输出：<b>Plain Text</b>
    std::cout << std::endl;

    boldItalicText->render(); // 输出：<i><b>Plain Text</b></i>
    std::cout << std::endl;

    delete text;
    delete boldText;
    delete boldItalicText;
}

void TestDecorator::translucencyDecorator() {
    TextComponent* text = new ConcreteTextComponent();

    BoldTextDecorator* boldText = new BoldTextDecorator(text);

    ItalicTextDecorator* boldItalicText = new ItalicTextDecorator(boldText);

    // 渲染文本
    text->render(); // 输出：Plain Text
    std::cout << std::endl;

    boldText->render(); // 输出：<b>Plain Text</b>
    std::cout << std::endl;

    boldItalicText->render(); // 输出：<i><b>Plain Text</b></i>
    std::cout << std::endl;

    delete text;
    delete boldText;
    delete boldItalicText;
}
