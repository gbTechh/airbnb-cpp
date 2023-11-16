class User {
public:
    // Constructor de la clase Usuario
    User(char* correo, int id, char* tipoUsuario);

    // Métodos para obtener los atributos del usuario
    char* getCorreo() const;
    int getId() const;
    char* getTipoUsuario() const;

private:
    // Atributos del usuario
    char* correo;
    int id;
    char* tipoUsuario;
};