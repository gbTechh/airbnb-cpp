#include "./Text.h"
#include <iostream>

Text::Text(char* _text) {
  text = _text;
}

// Implementación del método permisos para Guest
void Text::getText() {
    // Implementación específica de permisos para un Guest
    // Puedes agregar aquí lo que necesites para los permisos de un Guest
    std::cout << "Permisos de Host\n";
    // ...
}