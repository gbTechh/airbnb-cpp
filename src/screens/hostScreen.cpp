#include <iostream>
#include "./hostScreen.h"
#include "../components/input.h"
#include "../screenView.h"

HostScreen::HostScreen() {}

void HostScreen::show() {
    
    system("clear");
    std::cout<<"Pantalla de usuario Host\n";
    std::cout<<"Presiona 0 para regresar o m para ver el menú principal.\n\n";

    loginScreen();
}
void HostScreen::loginScreen() {
    system("clear");
    std::cout<<"Bienvenido usuario Host, por favor escoja una de las opciones, aprete 0 para regresar o m para ver el menú principal.\n\n";
    std::cout<<"1) Iniciar sesión\n";
    std::cout<<"2) Registrarse\n";
    char option = 'q';
    Input inputComponent("Escoja una opción:");
    option = inputComponent.displayChar();

    ScreenView screen;
    if(option == '0'){
        option = 'm';
        screen.start(option);
    }else if(option == '1'){
        loginShow();
    }else if(option == '2'){
        registerShow();
    }else if(option == 'm'){
        screen.start(option);
    }else{
        loginScreen();
    }    
}
void HostScreen::loginShow() {
    system("clear");
    std::cout<<"Por favor ingrese sus credenciales. Aprete 'y' para continuar 'n' para regresar o 'm' para ver el menú principal.\n";
    Input inputNext("Desea continar? y/n");
    char option = inputNext.displayChar();
    ScreenView screen;
    
    if(option == 'y'){
        Input inputUsername("Escriba su username:");
        char username = inputUsername.displayChar();
        Input inputPassword("Escriba su password:");
        char password = inputPassword.displayChar();
    }else if(option == 'n'){
        loginScreen(); 
    }else if(option == 'm'){
        screen.start(option);
    }else {
        loginShow();
    }
    
}
void HostScreen::registerShow() {
    
    Input inputComponent("Escoja una opción:");
    char username = inputComponent.displayChar();
}