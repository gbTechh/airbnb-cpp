#pragma once
#include "./baseScreen.h"

class AdminScreen: public BaseScreen {
public:
    AdminScreen();
    virtual void show() override;
    virtual void initFilesScreen() override;
    void loginScreen();
    void loginShow();
    void menuAdminShow();
    void countryShow(char &option);
    void countryCreate();
	void countryList();
    void countryEdit();

    void cityShow(char &option);
	void cityCreate();
	void cityList();
	void cityEdit();
   
    void alojamientosScreen(char &option);
    void tipoAlojamientoShow(char &option);
    void alojamientoShow(char &option);
    void tipoAlojamientoList();
    void tipoAlojamientoCreate();
    void tipoAlojamientoEdit();

};