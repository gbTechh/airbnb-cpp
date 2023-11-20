// #include <iostream>
// #include <fstream>
// #include <string.h>
// #include "Seed.h"

// Seed::Seed(const char* filename) : filename(filename), numLines(0) {
//     std::ifstream file(filename);

//     if (file) {
//         // Contar las líneas en el archivo
//         std::string line;
//         while (std::getline(file, line)) {
//             numLines++;
//         }
//         file.close();
//     }
// }

// void Store::fillData(const char** data) {
//     std::ofstream file(filename, std::ofstream::trunc);

//     if (!file) {
//         std::cout << "Error al abrir el archivo: " <<filename<< std::endl;
//     } else {
      
//       std::ofstream file(filename, std::ios::app); //std::ios::app abre el archivo para escribir datos sin sobrescribirt lo que ya habia
	
//       if (file) {
//           for(int i = 0; i < data.length ; i++){
//             file << data[i] << "\n";
//           }
//           file.close();
//           std::cout << "Seed ejecutado exitosamente para: " <<filename<< std::endl;
//       } else{
//         std::cout<<"Error al guardar los datos.";
//       }
//     }

    
// }

