#pragma once
#include "../models/Country.h"
#include "./Store.h"
#include "../helpers/String.h"

class CountryStore: public Store {
public:
    CountryStore();
    void addCountry(const Country& country);
    char** getAllCountries();
    char* getCountryById(char* id);
    bool editCountry(char* id, const Country& country);

private:
    Country* countries;
    int numCountries;
};