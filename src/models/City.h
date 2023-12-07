#pragma once

class City {
public:
    City(const char* name, const char* idCountry);
    City();
    
    const char* getName() const;   
    const char* getIdCountry() const;   
    void setName(const char* name);
    int getID() const;
    void getIdCountry();
 

private:
    char name[100];
    int id;
    char idCountry[100];
};