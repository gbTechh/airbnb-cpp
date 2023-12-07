#pragma once
#include "../models/City.h"
#include "./Store.h"
#include "../helpers/String.h"

class CityStore: public Store {
public:
    CityStore();
    void addCity(const City& city);
    char** getAllCities();
    char* getCityById(char* id);
    bool editCity(char* id, const City& city);

private:
    City* cities;
    int numCities;
};