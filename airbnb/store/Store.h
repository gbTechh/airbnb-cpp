#pragma once

class Store {
public:
    Store(const char* filename);
    void insertData(const char* data);
    char** getAllData();
    int getNumLines();
    int getNumLinesOfFile();

private:
    const char* filename;
    int numLines;
};
