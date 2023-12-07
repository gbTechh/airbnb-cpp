#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "AlojamientoStore.h"
#include "../models/Alojamiento.h"
#include "../helpers/String.h"
#include "./Store.h"

AlojamientoStore::AlojamientoStore() : Store("../src/database/files/alojamientos.txt"), alojamientos(nullptr), numAlojamientos(0) {
    std::ifstream file(filename);

    if (file) {
        numAlojamientos = getNumLinesOfFile();
    }
}


void AlojamientoStore::addAlojamiento(const Alojamiento& alojamiento) {
    
    int rowIndex = numAlojamientos + 1;
    int longChar = 0;

    String name(alojamiento.getName());
    String description(alojamiento.getDescription());
    String tipoAlojamiento(alojamiento.getIdTipoAlojamiento());
    String city(alojamiento.getIdCity());
    String host(alojamiento.getIdHost());

    char buffer[100]; 
    int longitud = std::sprintf(buffer, "%f", alojamiento.getPriceNigth());
    longChar = name.length() + description.length() + tipoAlojamiento.length() + city.length() + host.length() + longitud + 10;

    char* alojamientoInfo = new char[longChar];
    std::snprintf(alojamientoInfo, longChar, "%d;%s;%s;%s;%s;%s;%f", rowIndex, alojamiento.getName(), alojamiento.getDescription(), alojamiento.getIdTipoAlojamiento(), alojamiento.getIdCity(), alojamiento.getIdHost(), alojamiento.getPriceNigth());
    insertData(alojamientoInfo);
    
    delete[] alojamientoInfo;
    numAlojamientos++;
}

bool AlojamientoStore::editAlojamiento(char* id, const Alojamiento& alojamiento) {
    int longChar = 200;
    char* alojamientoInfo = new char[longChar];	

    char* data = getAlojamientoById(id);

    int numOfLine = std::stoi(id);

    if(data == nullptr){
        return false; 
    } else {
        std::snprintf(alojamientoInfo, longChar, "%s;%s", id, alojamiento.getName());
        int isEdited = editLine(numOfLine, alojamientoInfo);
        if(isEdited){
            return true;
        }else{
            return false;
        }
    }
}
char** AlojamientoStore::getAllAlojamientos() {
    return getAllData();
}

char* AlojamientoStore::getAlojamientoById(char* id) {
    char **data = getAllData();
    int count = 0;
    int lengthData = numAlojamientos;
    char separator = ';';
    char* returnData = nullptr;
    for(int i = 0; i < numAlojamientos; i++){
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
