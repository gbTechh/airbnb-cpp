#pragma once

class Store {
public:
    Store(const char* filename);
    void insertData(const char* data);
    char** getAllData();
    int getNumLines();
    int getNumLinesOfFile();
    void createFile();
    bool editLine(int numOfLine, char* newLine);

protected:
    int numLines;
    const char* filename;

};
