#include <iostream>
#include "./ArrayInt.h"
#include <stdexcept>

#define RED_TEXT "\033[1;31m"
#define RESET_TEXT "\033[0m"

ArrayInt::ArrayInt(int size) {
  length = 0;
  capacity = size;
  elements = new int[capacity];
}
ArrayInt::ArrayInt() {
  length = 0;
  capacity = 10;
  elements = new int[capacity];
}

ArrayInt::~ArrayInt() {
  delete[] elements;
}

void ArrayInt::push(int element) {
  if (length == capacity) {
    int* newElements = new int[2 * capacity];
    for (int i = 0; i < length; i++) {
      newElements[i] = elements[i];
    }
    delete[] elements;
    elements = newElements;
    capacity *= 2;
  }
  elements[length] = element;
  length++;
}
int ArrayInt::getIndex(int index) {
  if(index > length - 1){
    throw std::invalid_argument(RED_TEXT "Error: El indice del ArrayInt es mayor a la longitud. getIndex() method" RESET_TEXT);
  }
  return elements[index];
}

int ArrayInt::pop() {
  length = length - 1;
  int lastItem = elements[length];
  int* newElements = new int[length]; 
  for (int i = 0; i < length; i++) {
      newElements[i] = elements[i];
  }
  delete[] elements;
  elements = newElements;
  return lastItem;
}

int ArrayInt::shiftIndex(int index){
  if(index > length - 1){
    throw std::invalid_argument(RED_TEXT "Error: El indice del ArrayInt es mayor a la longitud. shiftIndex() method" RESET_TEXT);
  }
  int itemDeleted = elements[index]; 
  length = length - 1;
  int* newElements = new int[length]; 
  for (int i = 0; i < length; i++) {
    if(i == index){
      newElements[i] = elements[i + 1];
    } else {
      newElements[i] = elements[i];
    }
  }
  delete[] elements;
  elements = newElements;
  return itemDeleted;
}