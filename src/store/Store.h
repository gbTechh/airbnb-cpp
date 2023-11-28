#pragma once

class Store {
public:
    Store(const char* filename);
    void insertData(const char* data);
    char** getAllData();
    int getNumLines();
    int getNumLinesOfFile();
    void createFile();

    //variables
private:
protected:
    int numLines;
    const char* filename;

};
