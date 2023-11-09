#include <iostream>
#include <fstream>
#include <string.h>
#include "Store.h"

Store::Store(const char* filename) : filename(filename), numLines(0) {
    std::ifstream file(filename);

    if (file) {
        // Contar las líneas en el archivo
        std::string line;
        while (std::getline(file, line)) {
            numLines++;
        }
        file.close();
    }
}

void Store::insertData(const char* data) {
    std::ofstream file(filename, std::ios::app); //std::ios::app abre el archivo para escribir datos sin sobrescribirt lo que ya habia
	
    if (file) {
        file << data << "\n";
        file.close();
        numLines++;
    } else{
      std::cout<<"Error al guardar los datos.";
    }
}

char** Store::getAllData() {
    std::ifstream archivo(filename);
    char** lineas = nullptr;

    if (archivo.is_open()) {
        std::string linea;
        numLines = 0;

        while (std::getline(archivo, linea)) {
            char* newLine = new char[linea.length() + 1];
            strcpy(newLine, linea.c_str());

            char** temp = new char*[numLines + 1];
            memcpy(temp, lineas, numLines * sizeof(char*));
            temp[numLines] = newLine;

            delete[] lineas;
            lineas = temp;

            numLines++;
        }

        archivo.close();
    } else {
        std::cout << "No se pudo abrir el archivo." << std::endl;
    }

    return lineas;
}

int Store::getNumLines() {
    return numLines;
}
int Store::getNumLinesOfFile() {
    
  std::ifstream file(filename);
  if (!file.is_open()) {
      std::cout << "Error: No se pudo abrir el archivo " << filename << std::endl;
      return -1;
  }

  int lineCount = 0;
  std::string line;
  while (std::getline(file, line)) {
      lineCount++;
  }

  file.close();
  return lineCount;

}
