#pragma once

class BaseScreen {
public:
    BaseScreen();
    void cleanScreen();
    virtual void show() = 0;
    virtual void initFilesScreen() = 0;
    char getUserOptionChar(const char* message, const char* label);
    int getUserOptionInt(const char* message, const char* label);
    char* getUserOptionString(const char* message, const char* label);
    void returnMainMenu();
};