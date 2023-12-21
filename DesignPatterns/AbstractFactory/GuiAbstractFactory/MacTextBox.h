//
// Created by 40611 on 2023/10/26.
//

#ifndef NEWTESTDEMO_MACTEXTBOX_H
#define NEWTESTDEMO_MACTEXTBOX_H

#include "TextBox.h"
#include <iostream>
using namespace std;

// 具体产品：Mac文本框
class MacTextBox : public TextBox {
public:
    void paint() override;
};


#endif //NEWTESTDEMO_MACTEXTBOX_H
