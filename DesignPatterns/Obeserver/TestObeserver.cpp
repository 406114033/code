//
// Created by 40611 on 2023/11/22.
//

#include "TestObeserver.h"
#include "Subject.h"
#include "Obeserver.h"
#include "ConcreteObeserver.h"
#include "ConcreteSubject.h"

TestObeserver::TestObeserver() {

}

void TestObeserver::test() {
    Subject * subject = new ConcreteSubject();
    Obeserver * objA = new ConcreteObeserver("A");
    Obeserver * objB = new ConcreteObeserver("B");
    subject->attach(objA);
    subject->attach(objB);

    subject->setState(1);
    subject->notify();

    cout << "--------------------" << endl;
    subject->detach(objB);
    subject->setState(2);
    subject->notify();

    delete subject;
    delete objA;
    delete objB;
}
