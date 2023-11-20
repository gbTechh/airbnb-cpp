#include <iostream>
#include "./guestScreen.h"

GuestScreen::GuestScreen() {}

void GuestScreen::show() {
    
    cleanScreen();
    std::cout<<"Pantalla de Guest\n";
    std::cout<<"Presiona 0 para regresar o m para ver el menú principal.\n\n";


    
}

void GuestScreen::initFilesScreen() {
    
}