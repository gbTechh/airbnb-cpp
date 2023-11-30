#include <iostream>
#include "./adminScreen.h"
#include "../components/input.h"
#include "../screenView.h"
#include "../store/CountryStore.h"
#include "../store/UserStore.h"
#include "../models/Country.h"
#include "../colors.h"
#include "./baseScreen.h"

AdminScreen::AdminScreen() {}

void AdminScreen::show() {
    initFilesScreen();
    cleanScreen();
    loginScreen();
    
}

void AdminScreen::initFilesScreen() {
    CountryStore country;
    country.createFile();
    
    UserStore user;
    user.createFile();
    user.createAdmin();


}

void AdminScreen::loginScreen() {
    cleanScreen();
    std::cout<<VERDE<<"Pantalla de Administrador\n"<<RESET;
    char option = getUserOptionChar("Bienvenido administrador, por favor escoja una de las opciones, aprete m para ver el menú principal.\n\n1) Iniciar sesión\n", "Escoge una opción");

    if (option == '1') {
        loginShow();
    } else if (option == 'm') {
        returnMainMenu();
    } else {
        loginScreen();
    }    
}

//Show screens
void AdminScreen::loginShow() {
    cleanScreen();
    std::cout<<VERDE<<"Iniciar Sesión Adminsitrador\n"<<RESET;
    char option = getUserOptionChar("Esta a punto de iniciar sesión. Aprete 'y' para continuar 'n' para regresar o 'm' para ver el menú principal.\n", "Continuar y/n");
    if (option == 'y') {
        Input inputUsername("Escriba su email: ");
        char* username = inputUsername.displayString();
        Input inputPassword("Escriba su password: ");
        char* password = inputPassword.displayString();
        UserStore user;

        char* rol = "admin";
        bool isAuth = user.authUser(username, password, rol);

        if(!isAuth){
            loginShow();    
        }else{
            menuAdminShow();
        }
    } else if (option == 'n') {
        loginScreen();
    } else if(option == 'm'){
        returnMainMenu();
    } else {
        loginShow();
    }   
    
}
void AdminScreen::menuAdminShow() {
    cleanScreen();
    std::cout<<VERDE<<"Bienvenido Administrador\n"<<RESET;
    char option = getUserOptionChar("Por favor escoja una de las opciones, o aprete '0' para salir de adminsitrador o 'm' para ver el menú principal.\n1) Módulo de Países\n2) Módulo de ciudades\n3) Módulo de usuarios\n4) Módulo de alojamientos\n0) Salir de administrador\n", "Escoge una opción: ");


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
        returnMainMenu();
    }else {
        menuAdminShow();
    }
}
void AdminScreen::countryShow(char &option) {
    cleanScreen();
    char getOption;
    if(option == 'c'){
        getOption = getUserOptionChar("Módulo de países. Por favor escoja una de las opciones, o aprete '0' para retroceder o 'm' para ver el menú principal.\n1) Listar Países\n2) Crear Países\n3) Editar Países\n4) Eliminar Países\n0) Retroceder\nm) Volver al menu principal\n", "Escoge una opción: ");
        countryShow(getOption);
    }else {
        if(option == '1'){ //Listar pais
            countryList();               
        }else if(option == '2'){ //Crear pais
            countryCreate();
            char nextOption = getUserOptionChar("Seguir llenando datos? y/n o 'm' para vovler al menu principal.", "Escoge una opción: ");
            if(nextOption == 'y'){
                countryShow(option);
            } else if(nextOption == 'm'){
                returnMainMenu();
            } else {
                menuAdminShow();
            }

        }else if(option == '3'){ //Editar pais
            countryEdit();
        }else if(option == '4'){ // eliminar Pais
            
        }else if(option == '0'){
            menuAdminShow();
        }else if(option == 'm'){
            returnMainMenu();
        }else {
            char opt = 'c';
            countryShow(opt);
        }
    }
}
void AdminScreen::cityShow(char &option) {
    cleanScreen();
    char getOption;
    ScreenView screen;
    if(option == 'c'){
        getOption = getUserOptionChar("Módulo de ciudades. Por favor escoja una de las opciones, o aprete '0' para retroceder o 'm' para ver el menú principal.\n1) Listar ciudades\n2) Crear Ciudades\n3) Editar ciudades\n4) Eliminar ciudades\n", "Escoge una opción: ");
        cityShow(getOption);
    }else {
        if(option == '1'){ //Listar ciudad
            cityList();               
        }else if(option == '2'){ //Crear ciudad
            cityCreate();
            char nextOption = getUserOptionChar("Seguir llenando datos? y/n o 'm' para vovler al menu principal.", "Escoge una opción: ");
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


//country
void AdminScreen::countryCreate() {
    // cleanScreen();
    char* option = getUserOptionString("Por favor escriba el nombre de un país.", "Escriba el nombre:");
    
    CountryStore countryStore;
    Country newCountry(option);

    countryStore.addCountry(newCountry);
	delete[] option;
   
}
void AdminScreen::countryEdit(){
    cleanScreen();
    CountryStore countryStore;

    char **data = countryStore.getAllCountries();    
    int lengthData = countryStore.getNumLines();
    if(data != nullptr){
        std::cout<<"LISTADO DE PAISES: \n\n";   
        for(int i = 0; i <= lengthData - 1; i++){
            std::cout << "Pais :" << ": " << data[i] << std::endl;
        } 

        char* idOption = getUserOptionString("\nEscriba el id del país que va a editar.", "Escoge una opción: ");
        char* nameOption = getUserOptionString("Por favor escriba el nombre de un país.", "Escriba el nombre:");

    
        Country editCountry(nameOption);

        bool isEdited = countryStore.editCountry(idOption, editCountry);
        if(isEdited){
            std::cout<<VERDE<<"\nPaís Editado con éxito\n"<<RESET;
            char nextOption = getUserOptionChar("\nQuiere editar otro país?.", "Escoge una opción y/n: ");
            if(nextOption == 'y'){
                countryEdit();
            }else if(nextOption == 'n'){
                nextOption = 'c';
                countryShow(nextOption);
            } else {
                countryEdit();
            }
        }else{
            std::cout<<ROJO<<"\nNo se pudo editar!\n"<<RESET;
            char nextOption = getUserOptionChar("\nQuiere volver a intentarlo?.", "Escoge una opción y/n: ");
            if(nextOption == 'y'){
                countryEdit();
            }else if(nextOption == 'n'){
                nextOption = 'c';
                countryShow(nextOption);
            } else {
                countryEdit();
            }
        }

    }else {
        std::cout<<"No hay datos Por ahora...\n";
        char option = getUserOptionChar("Desea Agregar un país? y/n o 'm' para vovler al menu principal.", "Escoge una opción: ");
        if( option == 'y'){
            countryCreate();
        }else if( option == 'n'){
            option = 'c';
            countryShow(option);
        } else if( option == 'm'){
            returnMainMenu();
        } else {
            countryList();
        }
    }
}
void AdminScreen::countryList() {
    cleanScreen();
    CountryStore countryStore;

    char **data = countryStore.getAllCountries();
    int lengthData = countryStore.getNumLines();

    if(data != nullptr){
        std::cout<<"LISTADO DE PAISES: \n\n";
        for(int i = 0; i <= lengthData - 1; i++){
            std::cout << "Pais :" << ": " << data[i] << std::endl;
        }
       
        char option = getUserOptionChar("\nAprete cualquier tecla para regresar:", "Escriba: ");

        if(option){
            option = 'c';
            countryShow(option);
        }
    }else{
        std::cout<<"No hay datos Por ahora...\n";
        char option = getUserOptionChar("Desea Agregar un país? y/n o 'm' para vovler al menu principal.", "Escoge una opción: ");
        if( option == 'y'){
            countryCreate();
        }else if( option == 'n'){
            option = 'c';
            countryShow(option);
        } else if( option == 'm'){
            returnMainMenu();
        } else {
            countryList();
        }
    }
}

//city
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
    // char option = getUserOptionChar("Listando todos los países. Para retroceder aprete '0' o 'm' para ver el menú principal.");
    
    CountryStore countryStore;

    // countryStore.getCountryById();

    // char **data = countryStore.getAllCountriesById();
    // int count = 0;

    // while (data[count] != nullptr) {
    //     std::cout << "Pais :" << ": " << data[count] << std::endl;
    //     count++;
    // }
}