//
// Created by 40611 on 2023/10/26.
//

#include "MacFactory.h"
#include "MacButton.h"
#include "MacTextBox.h"

Button* MacFactory::createButton() {
    return new MacButton();
}

TextBox* MacFactory::createTextBox()  {
    return new MacTextBox();
}