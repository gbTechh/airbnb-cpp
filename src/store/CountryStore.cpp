#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
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
    
    int rowIndex = numCountries + 1;
	int longChar = 100;
    char* countryInfo = new char[longChar];
	
    std::snprintf(countryInfo, longChar, "%d;%s", rowIndex, country.getName());
    insertData(countryInfo);
    
    delete[] countryInfo;
    numCountries++;
}

bool CountryStore::editCountry(char* id, const Country& country) {
    int longChar = 100;
    char* countryInfo = new char[longChar];	

    char* data = getCountryById(id);

    int numOfLine = std::stoi(id);

    if(data == nullptr){
        return false; 
    } else {
        std::snprintf(countryInfo, longChar, "%s;%s", id, country.getName());
        int isEdited = editLine(numOfLine, countryInfo);
        if(isEdited){
            return true;
        }else{
            return false;
        }
    }
}
char** CountryStore::getAllCountries() {
    return getAllData();
}

char* CountryStore::getCountryById(char* id) {
    char **data = getAllData();
    int count = 0;
    int lengthData = numCountries;
    char separator = ';';
    char* returnData = nullptr;
    for(int i = 0; i < numCountries; i++){
        String line(data[i]);
        
        char** arrData = line.split(separator);
        
        char* idData = arrData[0];
        int isSameId = std::strcmp(idData, id);
        if(isSameId == 0){
            returnData = data[i];
        }
    }
  
    return returnData;
}


