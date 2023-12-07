#pragma once
#include "../models/User.h"

class BaseScreen {
public:
    BaseScreen();
    ~BaseScreen();
    void cleanScreen();
    virtual void show() = 0;
    virtual void initFilesScreen() = 0;
    char getUserOptionChar(const char* message, const char* label);
    int getUserOptionInt(const char* message, const char* label);
    char* getUserOptionString(const char* message, const char* label);
    float getUserOptionFloat(const char* message, const char* label);
    void returnMainMenu();

    void setCurrentUser(const char* user);
    char* getNameCurrentUser() const;
    char* getIdCurrentUser() const;

private:
    char* currentUser;
};