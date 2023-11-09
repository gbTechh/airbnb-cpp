#pragma once
#include "../models/Country.h"

class CountryStore {
public:
    CountryStore();
    void addCountry(const Country& country);
    char** getAllCountries();
    char** getAllCountriesById();

private:
    const char* filename;
    Country* countries;
    int numCountries;
};