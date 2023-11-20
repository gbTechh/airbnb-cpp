#include <iostream>
#include <fstream>
#include <cstring>
#include "CountryStore.h"
#include "../models/Country.h"
#include "./Store.h"

CountryStore::CountryStore() : Store("../src/database/files/countries.txt"), countries(nullptr), numCountries(0) {
    std::ifstream file(filename);

    if (file) {
        numCountries = getNumLinesOfFile();
    }
}

void CountryStore::addCountry(const Country& country) {
    // Añadir un país al final de la lista
    int rowIndex = numCountries + 1;
	int longChar = 100;
    char* countryInfo = new char[longChar];
	
    std::snprintf(countryInfo, longChar, "%d;%s", rowIndex, country.getName());
    insertData(countryInfo);
    
    delete[] countryInfo;
    numCountries++;
}

char** CountryStore::getAllCountries() {
    return getAllData();
}
char** CountryStore::getAllCountriesById() {
    char **data = getAllData();
    int count = 0;

    while (data[count] != nullptr) {
        // std::cout << "Pais" << ": " << data[count] << std::endl;
        count++;
        // char* ptr = data[count];

        // while (*ptr != ';') { 
        //     char currentChar = *ptr; 
            
        //     std::cout << currentChar << std::endl;
        //     ptr++;
        // }
        // while(data[count] == ';'){
        //     std::cout<<"detener";
        // }
        char* token = std::strtok(data[count], ";");
        while (token != nullptr) {
            std::cout << token << std::endl;
            token = std::strtok(nullptr, ";");
        }
    }
    return data;
}


