#pragma once


class ArrayInt {
public:
  ArrayInt(int size);
  ArrayInt();
  ~ArrayInt();
  void push(int element);
  int getIndex(int index);
  int pop();
  int shiftIndex(int index);
  int length;       

private:
  int* elements;  
  int capacity;   
};
