#include "./ArrayStr.h"
#include <iostream>
#include <stdexcept>
#include <cstring>

#define RED_TEXT "\033[1;31m"
#define RESET_TEXT "\033[0m"

ArrayStr::ArrayStr(int size) {
    this->elements = new char*[size];
    this->capacity = size;
    this->length = 0;
}

ArrayStr::ArrayStr() : ArrayStr(10) {
    // Constructor por defecto, inicializa con capacidad de 10
}

ArrayStr::~ArrayStr() {
    for (int i = 0; i < length; ++i) {
        delete[] elements[i];
    }
    delete[] elements;
}

void ArrayStr::push(const char* element) {
    if (length == capacity) {
        // Redimensionar si es necesario
        int newCapacity = 2 * capacity;
        char** newElements = new char*[newCapacity];

        for (int i = 0; i < length; ++i) {
            newElements[i] = elements[i];
        }

        delete[] elements;
        elements = newElements;
        capacity = newCapacity;
    }

    elements[length] = new char[strlen(element) + 1];
    strcpy(elements[length], element);
    length++;
}

const char* ArrayStr::getIndex(int index) {
    if (index < 0 || index >= length) {
        throw std::out_of_range(RED_TEXT "Error: Índice fuera de rango. getIndex() method" RESET_TEXT);
    }

    return elements[index];
}

const char* ArrayStr::pop() {
    if (length == 0) {
        throw std::out_of_range(RED_TEXT "Error: No hay elementos para hacer pop en ArrayStr" RESET_TEXT);
    }

    const char* lastItem = elements[length - 1];
    delete[] elements[length - 1];
    length--;

    return lastItem;
}

const char* ArrayStr::shiftIndex(int index) {
    if (index < 0 || index >= length) {
        throw std::out_of_range(RED_TEXT "Error: Índice fuera de rango. shiftIndex() method" RESET_TEXT);
    }

    const char* itemDeleted = elements[index];

    for (int i = index; i < length - 1; ++i) {
        elements[i] = elements[i + 1];
    }

    length--;

    return itemDeleted;
}

int ArrayStr::getLength() {
    return length;
}