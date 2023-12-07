#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "CityStore.h"
#include "../models/City.h"
#include "./Store.h"

CityStore::CityStore() : Store("../src/database/files/cities.txt"), cities(nullptr), numCities(0) {
    std::ifstream file(filename);

    if (file) {
        numCities = getNumLinesOfFile();
    }
}

void CityStore::addCity(const City& city) {
    
    int rowIndex = numCities + 1;
	  int longChar = 100;
    char* cityInfo = new char[longChar];
	
    std::snprintf(cityInfo, longChar, "%d;%s;%s", rowIndex, city.getIdCountry(), city.getName());
    insertData(cityInfo);
    
    delete[] cityInfo;
    numCities++;
}

bool CityStore::editCity(char* id, const City& city) {
    int longChar = 200;
    char* cityInfo = new char[longChar];	

    char* data = getCityById(id);

    int numOfLine = std::stoi(id);

    if(data == nullptr){
        return false; 
    } else {
        std::snprintf(cityInfo, longChar, "%s;%s;%s", id, city.getIdCountry(), city.getName());
        int isEdited = editLine(numOfLine, cityInfo);
        if(isEdited){
            return true;
        }else{
            return false;
        }
    }
}
char** CityStore::getAllCities() {
    return getAllData();
}

char* CityStore::getCityById(char* id) {
    char **data = getAllData();
    int count = 0;
    int lengthData = numCities;
    char separator = ';';
    char* returnData = nullptr;
    for(int i = 0; i < numCities; i++){
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
