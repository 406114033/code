//
// Created by 40611 on 2023/11/15.
//

#include "TestAdapter.h"
#include "Adapter.h"
#include "Adaptee.h"
#include "Target.h"

TestAdapter::TestAdapter() {

}

void TestAdapter::test() {
    cout << "adapter pattern test" << endl;
    Adaptee * adaptee  = new Adaptee();
    Target * tar = new Adapter(adaptee);
    tar->request();
    delete adaptee;
    delete tar;
}
