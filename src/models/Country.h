#pragma once

class Country {
public:
    Country(const char* name);
    Country();
    
    const char* getName() const;   
    void setName(const char* name);
    int getID() const;

private:
    char name[100];
    int id;
};