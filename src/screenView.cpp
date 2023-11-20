#include <iostream>
#include "./screenView.h"
#include "./screens/adminScreen.h"
#include "./screens/hostScreen.h"
#include "./screens/guestScreen.h"
#include "./components/input.h"

using namespace std;

ScreenView::ScreenView() {}

void ScreenView::start(char &input) {
    AdminScreen adminScreen;
    adminScreen.initFilesScreen();


    if(input == '1' || input == '2' || input == '3' || input == '0'){
        if (input == '0') {
            return;
        }
       
        char option = input;
        if (option == '1') {            
            adminScreen.show();   
            return;    
        } else if(option == '2') {
            HostScreen hostScreen;
            hostScreen.show();  
            return;
        } else if(option == '3'){
            GuestScreen guestScreen;
            guestScreen.show();
            return;
        } 
    }else if(input == 'm'){
        menuMain();
        Input inputComponent("Escoja una opción:");
        input = inputComponent.displayChar();
        start(input);
    } else {
        return;
    }
    
}

void ScreenView::menuMain(){
    system("clear");
    cout << "Bienvenido. Elija una de las opciones: \n";
    cout << "1) Eres administrador.\n";
    cout << "2) Eres usuario host.\n";
    cout << "3) Eres cliente.\n";
    cout << "0) Para salir.\n";
}