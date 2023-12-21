//
// Created by 40611 on 2023/10/26.
//

#include "WindowsFactory.h"
#include "WindowsButton.h"
#include "WindowsTextBox.h"


Button* WindowsFactory::createButton(){
    return new WindowsButton();
}

TextBox* WindowsFactory::createTextBox(){
    return new WindowsTextBox();
}