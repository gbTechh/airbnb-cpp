#include <iostream>
#include "./adminScreen.h"
#include "../components/input.h"
#include "../screenView.h"
#include "../store/CountryStore.h"
#include "../models/Country.h"

AdminScreen::AdminScreen() {}

char AdminScreen::getUserOption(const char* message, const char* label = "Escoja una opción") {
    system("cls");
    std::cout << message;
    Input inputComponent(label);
    char option = inputComponent.displayChar();

    return option;
}
int AdminScreen::getUserOptionInt(const char* message, const char* label) {
    system("cls");
    std::cout << message;
    Input inputComponent(label);
    int option = inputComponent.displayInt();

    return option;
}
char* AdminScreen::getUserOptionString(const char* message, const char* label) {
    system("cls");
    std::cout << message;
    Input inputComponent(label);
    char* option = inputComponent.displayString();

    return option;
}

void AdminScreen::show() {
    
    system("cls");
    std::cout<<"Pantalla de Administrador\n";
    std::cout<<"Presiona 0 para regresar o m para ver el menú principal.\n\n";

    loginScreen();
    
}

void AdminScreen::loginScreen() {
    char option = getUserOption("Bienvenido administrador, por favor escoja una de las opciones, aprete 0 para regresar o m para ver el menú principal.\n\n1) Iniciar sesión\n2) Registrarse\n");
    ScreenView screen;

    if (option == '0') {
        option = 'm';
        screen.start(option);
    }
    if (option == '1') {
        loginShow();
    } else if (option == '2') {
        registerShow();
    } else if (option == 'm') {
        screen.start(option);
    } else {
        loginScreen();
    }    
}


void AdminScreen::loginShow() {
    char option = getUserOption("Por favor ingrese sus credenciales. Aprete 'y' para continuar 'n' para regresar o 'm' para ver el menú principal.\n");
    ScreenView screen;
    if (option == 'y') {
        Input inputUsername("Escriba su username:");
        char username = inputUsername.displayChar();
        Input inputPassword("Escriba su password:");
        char password = inputPassword.displayChar();

        menuAdminShow();
    } else if (option == 'n') {
        loginScreen();
    } else if(option == 'm'){
        screen.start(option);
    } else {
        loginShow();
    }   
    
}

void AdminScreen::registerShow() {
    
    char option = getUserOption("Escoja una opción:");
}

void AdminScreen::menuAdminShow() {
    char option = getUserOption("Bienvenido administrador. Por favor escoja una de las opciones, o aprete '0' para salir de adminsitrador o 'm' para ver el menú principal.\n1) Módulo de Países\n2) Módulo de ciudades\n3) Módulo de usuarios\n4) Módulo de alojamientos\n");

    ScreenView screen;

    if(option == '1'){
        char opt = 'c';
        countryShow(opt);        
    }else if(option == '2'){
        char opt = 'c';
        cityShow(opt);
    }else if(option == '3'){
        
    }else if(option == '4'){
        
    }else if(option == '0'){
        loginScreen();
    }else if(option == 'm'){
        screen.start(option);
    }else {
        menuAdminShow();
    }
}
void AdminScreen::countryShow(char &option) {
    char getOption;
    ScreenView screen;
    if(option == 'c'){
        getOption = getUserOption("Módulo de países. Por favor escoja una de las opciones, o aprete '0' para retroceder o 'm' para ver el menú principal.\n1) Listar Países\n2) Crear Países\n3) Editar Países\n4) Eliminar Países\n0) Retroceder\nm) Volver al menu principal\n");
        countryShow(getOption);
    }else {
        if(option == '1'){ //Listar pais
            countryList();               
        }else if(option == '2'){ //Crear pais
            countryCreate();
            char nextOption = getUserOption("Seguir llenando datos? y/n o 'm' para vovler al menu principal.");
            if(nextOption == 'y'){
                countryShow(option);
            } else if(nextOption == 'm'){
                screen.start(nextOption);
            } else {
                menuAdminShow();
            }

        }else if(option == '3'){ //Editar pais
            
        }else if(option == '4'){ // eliminar Pais
            
        }else if(option == '0'){
            menuAdminShow();
        }else if(option == 'm'){
            screen.start(option);
        }else {
            char opt = 'c';
            countryShow(opt);
        }
    }
}
//country
void AdminScreen::countryCreate() {
    char* option = getUserOptionString("Por favor escriba el nombre de un país.", "Escriba el nombre:");
    
    CountryStore countryStore;
    Country newCountry(option);

    // Luego, llama al método addCountry para agregar el nuevo país a la tienda
    countryStore.addCountry(newCountry);
	delete[] option;
   
}
void AdminScreen::countryList() {
    // char option = getUserOption("Listando todos los países. Para retroceder aprete '0' o 'm' para ver el menú principal.");
    
    CountryStore countryStore;

    char **data = countryStore.getAllCountries();
    int count = 0;

    while (data[count] != nullptr) {
        std::cout << "Pais :" << ": " << data[count] << std::endl;
        count++;
    }
}

//city
void AdminScreen::cityShow(char &option) {
    char getOption;
    ScreenView screen;
    if(option == 'c'){
        getOption = getUserOption("Módulo de ciudades. Por favor escoja una de las opciones, o aprete '0' para retroceder o 'm' para ver el menú principal.\n1) Listar ciudades\n2) Crear Ciudades\n3) Editar ciudades\n4) Eliminar ciudades\n");
        cityShow(getOption);
    }else {
        if(option == '1'){ //Listar ciudad
            cityList();               
        }else if(option == '2'){ //Crear ciudad
            cityCreate();
            char nextOption = getUserOption("Seguir llenando datos? y/n o 'm' para vovler al menu principal.");
            if(nextOption == 'y'){
                cityShow(option);
            } else if(nextOption == 'm'){
                screen.start(nextOption);
            } else {
                menuAdminShow();
            }

        }else if(option == '3'){ //Editar ciudad
            
        }else if(option == '4'){ // eliminar ciudad
            
        }else if(option == '0'){
            char opt = 'c';
            cityShow(opt);
        }else if(option == 'm'){
            screen.start(option);
        }else {
            char opt = 'c';
            cityShow(opt);
        }
    }
}


void AdminScreen::cityCreate() {
    std::cout<<"Lista de países:\n";
    countryList();

    char* option = getUserOptionString("Por favor escriba el ID del país al que pertenece la ciudad.", "Id del país:");
    
    CountryStore countryStore;
    Country newCountry(option);

    // Luego, llama al método addCountry para agregar el nuevo país a la tienda
    countryStore.addCountry(newCountry);
	delete[] option;
}
void AdminScreen::cityList() {
    // char option = getUserOption("Listando todos los países. Para retroceder aprete '0' o 'm' para ver el menú principal.");
    
    CountryStore countryStore;

    countryStore.getAllCountriesById();
    // char **data = countryStore.getAllCountriesById();
    // int count = 0;

    // while (data[count] != nullptr) {
    //     std::cout << "Pais :" << ": " << data[count] << std::endl;
    //     count++;
    // }
}