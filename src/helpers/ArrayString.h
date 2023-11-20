#pragma once

class ArrayString {
public:
    ArrayString(int rows, int columns);
    ArrayString();
    ~ArrayString();
    void push(const char* element);
    const char* getIndex(int row, int column);
    const char* pop();
    const char* shiftIndex(int row, int column);
    int getRows();
    int getColumns();

    int length;
private:
    char*** elements;
    int rows;
    int columns;
    int capacityRows;
    int capacityColumns;
};
