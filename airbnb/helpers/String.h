#pragma once

class String {
public:
  String();
  String(const char* str);
  String(const String& o);  
  ~String();
  char* get() const;
  char* cin();
  void print() const;

private:
    char* data;
};