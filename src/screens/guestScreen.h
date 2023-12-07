#pragma once
#include "./baseScreen.h"
#include "../helpers/ArrayStr.h"

class GuestScreen: public BaseScreen {
public:
    GuestScreen();
    virtual void show() override;
    virtual void initFilesScreen() override;
    void loginScreen();
    void loginShow();
    void registerShow();
    void menuGuestShow();
    void findAlojamientoShow();
    ArrayStr getAllAlojamientosBySomeId(int index, char* id);
    void findByCity();
    void findByType();
    void findByPrice();
    void findByName();
    void formatterAlojamiento(const char* text);
};