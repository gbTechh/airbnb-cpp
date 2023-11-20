#include "./Guest.h"
#include <iostream>

Guest::Guest(const char* _email, int _id, const char* _name, const char* _password)
    : User(_email, _id, _name, _password) {
      setTipoUsuario(0);
    }

// Implementación del método permisos para Guest
void Guest::permisos() {
    // Implementación específica de permisos para un Guest
    // Puedes agregar aquí lo que necesites para los permisos de un Guest
    std::cout << "Permisos de Guest\n";
    // ...
}