#pragma once

class City {
public:
    City(const char* name);
    City();
    
    const char* getName() const;   
    void setName(const char* name);
    int getID() const;
    void getIdCountry();
 

private:
    char name[100];
    int id;
    int idcountry;
};