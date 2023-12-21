//
// Created by 40611 on 2023/10/26.
//

#ifndef NEWTESTDEMO_MACBUTTON_H
#define NEWTESTDEMO_MACBUTTON_H

#include "Button.h"
#include <iostream>
using namespace std;

// 具体产品：Mac按钮
class MacButton : public Button {
public:
    void paint() override;
};


#endif //NEWTESTDEMO_MACBUTTON_H
