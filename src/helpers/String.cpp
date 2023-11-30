#include <iostream>
#include <cstring>
#include <limits>
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
  std::cin.getline(str, maxSize);
  delete[] data;
  data = new char[strlen(str) + 1];
  strcpy(data, str);

  return str;
}

int String::length() {
  int i = 0;
  while(data[i] != '\0' ){    
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

char** String::split(char separator) {
  int count = 1;
  for (int i = 0; i < length(); ++i) {
    if (data[i] == separator) {
      ++count;
    }
  }

  char** result = new char*[count];
  int start = 0;
  int resultIndex = 0;


  for (int i = 0; i <= length(); ++i) {
    if (data[i] == separator || data[i] == '\0') {
      
      result[resultIndex] = new char[i - start + 1];

      std::memcpy(result[resultIndex], data + start, i - start);
      result[resultIndex][i - start] = '\0';

      start = i + 1;
      ++resultIndex;
    }
  }

  return result;
}