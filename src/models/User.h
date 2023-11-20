#pragma once

class User {
public:
    User(const char* email, const char* name, const char* password);

    const char* getEmail() const;
    int getId() const;
    const char* getName() const;
    const char* getPassword() const;
    const char* getTipoUsuario() const;
    void setName(const char* name);
    void setId(int id);
    void setEmail(const char* email);
    void setPassword(const char* password);
    void setTipoUsuario(int rol);
    virtual void permisos();


    const char* email;
    const char* name;
    const char* password;
    int id;
    const char* tipoUsuario[3] = {"admin", "host", "guest"};
    const char* rol;
private:
    // Atributos del usuario
   
};
