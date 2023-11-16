#include <iostream>
#include <cstring>
#include "./String.h"


String::String() : data(nullptr) {}

String::String(const char* str) {
  if (str) {
      data = new char[strlen(str) + 1];
      strcpy(data, str);
  } else {
      data = nullptr;
  }
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
