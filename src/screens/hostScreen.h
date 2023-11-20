#pragma once
#include "./baseScreen.h"

class HostScreen: public BaseScreen {
public:
    HostScreen();
    virtual void show() override;
    virtual void initFilesScreen() override;
    void loginScreen();
    void loginShow();
    void registerShow();
};