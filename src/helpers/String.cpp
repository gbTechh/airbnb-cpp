#include <iostream>
#include <cstring>
#include "./String.h"


String::String() : data(nullptr), lengthStr(0) {}

String::String(const char* str) {
  if (str) {
      data = new char[strlen(str) + 1];
      strcpy(data, str);
  } else {
      data = nullptr;
  }
  lengthStr = 0;
}

String::String(const String& o) {
  if (o.data) {
      data = new char[strlen(o.data) + 1];
      strcpy(data, o.data);
  } else {
      data = nullptr;
  }
}

String::~String() {
  delete[] data;
}

char* String::get() const {
  return data;
}

void String::print() const {
  std::cout << (data ? data : "Empty String") << std::endl;
}

char* String::cin() {
  const int maxSize = 256;
  char* str = new char[maxSize];
  std::cin.ignore();
  std::cin.getline(str, maxSize);
  delete[] data;
  data = new char[strlen(str) + 1];
  strcpy(data, str);
  return str;
}

int String::length() {
  int i = 0;
  while(data[i] != '\0' ){
    std::cout<<data[i];
    i++;
  }
  lengthStr = i;
  return i;
}
bool String::includes(char* text) {
  int i = 0;
    while (data[i] != '\0') {
        int j = 0;
        int temp_i = i; 

        while (data[temp_i] == text[j] && text[j] != '\0') {
            temp_i++;
            j++;
        }

        if (text[j] == '\0') {           
            return true;
        }

        i++;
    }

    return false;
}