#pragma once

#include <iostream>
#include <cstring>

class Input {
public:
    Input(const char* label);
    
    int displayInt();
    float displayFloat();
    double displayDouble();
    char displayChar();
    char* displayString();

private:
    const char* label;
    int valueInt;
    double valueDouble;
    float valueFloat;
    char valueChar;
};