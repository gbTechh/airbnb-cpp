#pragma once
#include "../models/Country.h"
#include "./Store.h"

class CountryStore: public Store {
public:
    CountryStore();
    void addCountry(const Country& country);
    char** getAllCountries();
    char** getAllCountriesById();

private:
    Country* countries;
    int numCountries;
};