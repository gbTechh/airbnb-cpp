#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "TipoAlojamientoStore.h"
#include "../models/TipoAlojamiento.h"
#include "./Store.h"

TipoAlojamientoStore::TipoAlojamientoStore() : Store("../src/database/files/tipoalojamientos.txt"), tiposAlojamientos(nullptr), numTiposAlojamientos(0) {
    std::ifstream file(filename);

    if (file) {
        numTiposAlojamientos = getNumLinesOfFile();
    }
}

void TipoAlojamientoStore::addTipoAlojamiento(const TipoAlojamiento& tipoAlojamiento) {
    
    int rowIndex = numTiposAlojamientos + 1;
	  int longChar = 100;
    char* tipoAlojamientoInfo = new char[longChar];
	
    std::snprintf(tipoAlojamientoInfo, longChar, "%d;%s", rowIndex, tipoAlojamiento.getName());
    insertData(tipoAlojamientoInfo);
    
    delete[] tipoAlojamientoInfo;
    numTiposAlojamientos++;
}

bool TipoAlojamientoStore::editTipoAlojamiento(char* id, const TipoAlojamiento& tipoAlojamiento) {
    int longChar = 200;
    char* tipoAlojamientoInfo = new char[longChar];	

    char* data = getTipoAlojamientoById(id);

    int numOfLine = std::stoi(id);

    if(data == nullptr){
        return false; 
    } else {
        std::snprintf(tipoAlojamientoInfo, longChar, "%s;%s", id, tipoAlojamiento.getName());
        int isEdited = editLine(numOfLine, tipoAlojamientoInfo);
        if(isEdited){
            return true;
        }else{
            return false;
        }
    }
}
char** TipoAlojamientoStore::getAllTiposAlojamientos() {
    return getAllData();
}

char* TipoAlojamientoStore::getTipoAlojamientoById(char* id) {
    char **data = getAllData();
    int count = 0;
    int lengthData = numTiposAlojamientos;
    char separator = ';';
    char* returnData = nullptr;
    for(int i = 0; i < numTiposAlojamientos; i++){
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
