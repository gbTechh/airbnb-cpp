#pragma once
#include "./baseScreen.h"

class AdminScreen: public BaseScreen {
public:
    AdminScreen();
    virtual void show() override;
    void loginScreen();
    void loginShow();
    void menuAdminShow();
    void countryShow(char &option);
    void countryCreate();
	void countryList();

    void cityShow(char &option);
	void cityCreate();
	void cityList();
   
};