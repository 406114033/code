//
// Created by 40611 on 2023/10/10.
//

#include "Singleton.hpp"
#include <iostream>
using namespace std;

Singleton* Singleton::instance = nullptr;

Singleton::Singleton() {

}

Singleton *Singleton::getInstance() {
    if(instance == nullptr){
        instance = new Singleton();
    }
    return instance;
}

void Singleton::showMessage() {
    cout << " hello Singleton Pattern" << endl;
}
