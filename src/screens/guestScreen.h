#pragma once
#include "./baseScreen.h"

class GuestScreen: public BaseScreen {
public:
    GuestScreen();
    virtual void show() override;
    virtual void initFilesScreen() override;
    void loginScreen();
    void loginShow();
    void registerShow();
};