#include "./Admin.h"
#include <iostream>

Admin::Admin(const char* _email, const char* _name, const char* _password)
    : User(_email, _name, _password) {
      setTipoUsuario(0);
    }

// Implementación del método permisos para Admin
void Admin::permisos() {
    // Implementación específica de permisos para un Admin
    // Puedes agregar aquí lo que necesites para los permisos de un Admin
    std::cout << "Permisos de Administrador\n";
    // ...
}