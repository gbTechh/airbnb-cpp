#include "input.h"
#include "../helpers/String.h"

Input::Input(const char* label) : label(label), valueInt(0), valueDouble(0.0), valueFloat(0.0) {
    
}

int Input::displayInt() {
    std::cout << label << "\n";
    std::cout << "-> ";
    std::cin >> valueInt;
    std::cout << "--------------------------\n";
    return valueInt;
}

float Input::displayFloat() {
    std::cout << label << "\n";
    std::cout << "-> ";
    std::cin >> valueFloat;
    std::cout << "--------------------------\n";
    return valueFloat;
}

double Input::displayDouble() {
    std::cout << label << "\n";
    std::cout << "-> ";
    std::cin >> valueDouble;
    std::cout << "--------------------------\n";
    return valueDouble;
}
char Input::displayChar() {
    char corner = 218;
    std::cout<<"\n";
    std::cout << corner<<"--------------------------\n";
    std::cout << "|"<<label << "\n";
    std::cout << "|-> ";
    std::cin >> valueChar;
    std::cout << "--------------------------\n";
    return valueChar;
}

char* Input::displayString() {
    char corner = 218;
    std::cout << "\n";
    std::cout << corner << "--------------------------\n";
    std::cout << "|" << label << "\n";
    std::cout << "|-> ";

    String str;
    char *input = str.cin();
    
    std::cout << "--------------------------\n";
    return input;
}