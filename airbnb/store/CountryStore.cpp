#include <iostream>
#include <fstream>
#include <cstring>
#include "CountryStore.h"
#include "../models/Country.h"
#include "./Store.h"

CountryStore::CountryStore() : filename("countries.txt"), countries(nullptr), numCountries(0) {
    std::ifstream file(filename);

    if(file){
      Store store(filename);
      numCountries = store.getNumLinesOfFile();
    }
    //std::ifstream file(filename, std::ios::in);

    // if (file) {
    //     // Leer el número de países
    //     file.read(reinterpret_cast<char*>(&numCountries), sizeof(int));

    //     // Reservar memoria para los países
    //     countries = new Country[numCountries];

    //     // Leer los países desde el archivo
    //     for (int i = 0; i < numCountries; i++) {
    //         char name[100];
    //         file.read(name, sizeof(name));
    //         int id;
    //         file.read(reinterpret_cast<char*>(&id), sizeof(int));
    //         countries[i] = Country(name, id);
    //     }

    //     file.close();
    // }
}

void CountryStore::addCountry(const Country& country) {
    // Añadir un país al final de la lista
    int rowIndex = numCountries + 1;
	int longChar = 100;
    char* countryInfo = new char[longChar];
	
    std::snprintf(countryInfo, longChar, "%d;%s", rowIndex, country.getName());
    Store store(filename);
    store.insertData(countryInfo);
    
    delete[] countryInfo;
    numCountries++;
}

char** CountryStore::getAllCountries() {
	Store store(filename);
    return store.getAllData();
}
char** CountryStore::getAllCountriesById() {
	Store store(filename);
    char **data = store.getAllData();
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


