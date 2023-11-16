#pragma once

class AdminScreen {
public:
    AdminScreen();
    void show();
    void loginScreen();
    void loginShow();
    void registerShow();
    void menuAdminShow();
    void countryShow(char &option);
    void countryCreate();
	void countryList();

    void cityShow(char &option);
	void cityCreate();
	void cityList();
private:
    char getUserOption(const char* messag, const char* label);
    int getUserOptionInt(const char* messag, const char* label);
    char* getUserOptionString(const char* message, const char* label);
};