#include "./City.h"
#include <iostream>
#include <cstring>

City::City(const char* name) {
    std::strncpy(this->name, name, sizeof(this->name));
    this->name[sizeof(this->name) - 1] = '\0'; 
}

const char* City::getName() const {
    return name;
}

void City::setName(const char* name) {
    if (std::strlen(name) <= sizeof(this->name) - 1) {
        std::strncpy(this->name, name, sizeof(this->name));
        this->name[sizeof(this->name) - 1] = '\0'; // Asegurar que la cadena esté terminada correctamente
    } else {
        std::cout << "Error: El nombre es demasiado largo. Se permiten un máximo de " << sizeof(this->name) - 1 << " caracteres." << std::endl;
    }
}
