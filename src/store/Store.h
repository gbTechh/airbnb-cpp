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
    // int getNumOfLineFromId(char* id);
    //variables
private:
protected:
    int numLines;
    const char* filename;

};
