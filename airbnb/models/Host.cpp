#include "./Host.h"
#include <iostream>

Host::Host(const char* _email, const char* _name, const char* _password)
    : User(_email, _name, _password) {
      setTipoUsuario(0);
    }

// Implementación del método permisos para Guest
void Host::permisos() {
    // Implementación específica de permisos para un Guest
    // Puedes agregar aquí lo que necesites para los permisos de un Guest
    std::cout << "Permisos de Host\n";
    // ...
}