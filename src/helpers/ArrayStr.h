#pragma once

class ArrayStr {
public:
    ArrayStr(int size);
    ArrayStr();
    ~ArrayStr();
    void push(const char* element);
    const char* getIndex(int index);
    const char* pop();
    const char* shiftIndex(int index);
    int getLength();

private:
    char** elements;
    int capacity;
    int length;
};