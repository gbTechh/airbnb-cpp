#include "./User.h"

// Implementación del constructor de la clase Usuario
User::User(char* correo, int id, char* tipoUsuario)
    : correo(correo), id(id), tipoUsuario(tipoUsuario) {}

// Implementación de los métodos para obtener los atributos del usuario
char* User::getCorreo() const {
    return correo;
}

int User::getId() const {
    return id;
}

char* User::getTipoUsuario() const {
    return tipoUsuario;
}