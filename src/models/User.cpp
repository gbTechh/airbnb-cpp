#include "./User.h"

// Implementación del constructor de la clase Usuario
User::User(const char* _email, int _id, const char* _name, const char* _password)
    : email(_email), id(_id), name(_name), password(_password) {}

// Implementación de los métodos para obtener los atributos del usuario
const char* User::getEmail() const {
    return email;
}

int User::getId() const {
    return id;
}

const char* User::getName() const {
    return name;
}

const char* User::getPassword() const {
    return password;
}

const char* User::getTipoUsuario() const {
    return rol;
}

void User::setName(const char* _name) {
    name = _name;
}

void User::setId(int _id) {
    id = _id;
}

void User::setEmail(const char* _email) {
    email = _email;
}

void User::setPassword(const char* _password) {
    password = _password;
}

void User::setTipoUsuario(const int _rol) {
    rol = tipoUsuario[_rol];
}

void User::permisos() {
    // Implementación de los permisos
}
