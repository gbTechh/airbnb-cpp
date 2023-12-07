#include <iostream>
#include "./adminScreen.h"
#include "../components/input.h"
#include "../screenView.h"
#include "../store/CountryStore.h"
#include "../store/CityStore.h"
#include "../store/UserStore.h"
#include "../store/TipoAlojamientoStore.h"
#include "../models/Country.h"
#include "../models/City.h"
#include "../models/TipoAlojamiento.h"
#include "../colors.h"
#include "./baseScreen.h"
#include "../helpers/String.h"

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

    CityStore city;
    city.createFile();

    TipoAlojamientoStore tipoAlojamiento;
    tipoAlojamiento.createFile();

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
        char* userAuth = user.authUser(username, password, rol);

        if(userAuth == nullptr){
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
        char opt = 'c';
        alojamientosScreen(opt);    
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
            char nextOption = getUserOptionChar("\nSeguir llenando datos? y/n o 'm' para volver al menu principal.", "Escoge una opción: ");
            if(nextOption == 'y'){
                cityShow(option);
            } else if(nextOption == 'm'){
                screen.start(nextOption);
            } else {
                menuAdminShow();
            }

        }else if(option == '3'){ //Editar ciudad
            cityEdit();
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
    cleanScreen();
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
        char option = getUserOptionChar("Desea Agregar un país? Aprete 'm' para volver al menu principal.", "Agregar ciudad y/n: ");
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
void AdminScreen::cityList() {
    cleanScreen();
    CityStore cityStore;

    char **data = cityStore.getAllCities();
    int lengthData = cityStore.getNumLines();

    if(data != nullptr){
        std::cout<<"LISTADO DE Ciudades: \n\n";
        for(int i = 0; i <= lengthData - 1; i++){
            std::cout << "Ciudad :" << ": " << data[i] << std::endl;
        }
       
        char option = getUserOptionChar("\nAprete cualquier tecla para regresar:", "Escriba: ");

        if(option){
            option = 'c';
            cityShow(option);
        }
    }else{
        std::cout<<"No hay datos Por ahora...\n";
        char option = getUserOptionChar("Desea Agregar una ciudad? Aprete 'm' para volver al menu principal.", "Agregar ciudad y/n: ");
        if( option == 'y'){
            cityCreate();
        }else if( option == 'n'){
            option = 'c';
            cityShow(option);
        } else if( option == 'm'){
            returnMainMenu();
        } else {
            cityList();
        }
    }
}
void AdminScreen::cityCreate() {
    cleanScreen();
    CountryStore countryStore;

    char **data = countryStore.getAllCountries();
    int lengthData = countryStore.getNumLines();

    if(data != nullptr){
        std::cout<<"LISTADO DE PAISES: \n\n";
        for(int i = 0; i <= lengthData - 1; i++){
            std::cout << "Pais :" << ": " << data[i] << std::endl;
        }        

        char* countrySelected = nullptr;

        do {
            char* option = getUserOptionString("\nPara agregar una ciudad seleccione el id de un país", "Escriba el id:");
            countrySelected = countryStore.getCountryById(option);
            if(countrySelected == nullptr){
                std::cout <<ROJO<< "\nID inválido. Ingrese nuevamente\n"<<RESET;
            }
            delete[] option;
        }
        while (countrySelected == nullptr);
        
        char separator = ';';
        String countryData(countrySelected);
        char** dataCountry = countryData.split(separator);
        char* idCountry = dataCountry[0];

        if(countrySelected != nullptr){
            char* name = getUserOptionString("Por favor escriba el nombre de la ciudad.", "Nombre de ciudad:");    
            CityStore cityStore;
            
            City newCity(name, idCountry);

            cityStore.addCity(newCity);
            delete[] name;
        }

        delete[] countrySelected;
        delete[] idCountry;
        delete[] dataCountry;



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
void AdminScreen::cityEdit(){
    cleanScreen();
    CityStore cityStore;

    char **data = cityStore.getAllCities();
    int lengthData = cityStore.getNumLines();

    if(data != nullptr){
        std::cout<<VERDE<<"LISTADO DE CIUDADES: \n\n"<<RESET;   
        for(int i = 0; i <= lengthData - 1; i++){
            std::cout << "Ciudad :" << ": " << data[i] << std::endl;
        } 

         
        char* cityById = nullptr;
        char* idOption = nullptr;
        char* name = nullptr;
        char* idCountry = nullptr;
        do {
            idOption = getUserOptionString("\nEscriba el id de la ciudad que va a editar.", "Escriba el id: ");
            cityById = cityStore.getCityById(idOption);
            if(cityById == nullptr){
                std::cout <<ROJO<< "\nID inválido. Ingrese nuevamente\n"<<RESET;
            }
        }
        while (cityById == nullptr);

        if(cityById != nullptr){
            char nameOption = getUserOptionChar("\nDesea editar el nombre?", "Escoge una opción y/n: ");
            if(nameOption == 'y'){
                name = getUserOptionString("Por favor escriba el nuevo nombre de la ciudad", "Escriba el nombre:");
            } 
            char countryOption = getUserOptionChar("\nDesea editar el país al que pertenece?", "Escoge una opción y/n: ");
            if(countryOption == 'y'){
                CountryStore countryStore;
                char **data = countryStore.getAllCountries();
                int lengthData = countryStore.getNumLines();
                std::cout<<VERDE<<"\nLISTADO DE PAISES: \n\n"<<RESET;
                for(int i = 0; i <= lengthData - 1; i++){
                    std::cout << "Pais :" << ": " << data[i] << std::endl;
                }
                char* countrySelected = nullptr;
                do {
                    idCountry = getUserOptionString("\nSelecciona el id del país", "Escriba el id:");
                    countrySelected = countryStore.getCountryById(idCountry);
                    if(countrySelected == nullptr){
                        std::cout<<ROJO<<"\nID inválido. Ingrese nuevamente\n"<<RESET;
                    }      
                }
                while(countrySelected == nullptr);
                delete[] countrySelected;
                delete[] data;
            }

            City editCity(name, idCountry);
            bool isEdited = cityStore.editCity(idOption, editCity);
            if(isEdited){
                std::cout<<VERDE<<"\nCiudad editada con éxito\n"<<RESET;
                char nextOption = getUserOptionChar("\nQuiere editar otra ciudad?.", "Escoge una opción y/n: ");
                if(nextOption == 'y'){
                    cityEdit();
                }else if(nextOption == 'n'){
                    nextOption = 'c';
                    cityShow(nextOption);
                } else {
                    cityEdit();
                }
            }else{
                std::cout<<ROJO<<"\nNo se pudo editar!\n"<<RESET;
                char nextOption = getUserOptionChar("\nQuiere volver a intentarlo?.", "Escoge una opción y/n: ");
                if(nextOption == 'y'){
                    cityEdit();
                }else if(nextOption == 'n'){
                    nextOption = 'c';
                    cityShow(nextOption);
                } else {
                    cityEdit();
                }
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

void AdminScreen::alojamientosScreen(char &option){
    cleanScreen();
    char getOption;
    ScreenView screen;
    if(option == 'c'){
        getOption = getUserOptionChar("Módulo de Alojamientos. Por favor escoja una de las opciones, o aprete '0' para retroceder o 'm' para ver el menú principal.\n1) Ir a tipos de alojamientos\n2) Ir a alojamientos\n", "Escoge una opción: ");
        alojamientosScreen(getOption);
    }else {
        if(option == '1'){ //Tipos de alojamientos
            option = 'c';
            tipoAlojamientoShow(option);               
        }else if(option == '2'){ //Alojamientos
            option = 'c';
            alojamientoShow(option);
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
//Tipo alojamiento
void AdminScreen::tipoAlojamientoShow(char &option){
    cleanScreen();
    char getOption;
    ScreenView screen;
    if(option == 'c'){
        getOption = getUserOptionChar("Módulo de Tipos de alojamientos. Por favor escoja una de las opciones, o aprete '0' para retroceder o 'm' para ver el menú principal.\n\n1) Listar todos los tipos de alojamientos\n2) Crear nuevo tipo de alojamiento\n3) Editar tipo de alojamiento\n4) Eliminar tipo de alojamiento\n\n", "Escoge una opción: ");
        tipoAlojamientoShow(getOption);
    }else {
        if(option == '1'){ //Listar ciudad
            tipoAlojamientoList();               
        }else if(option == '2'){ //Crear ciudad
            tipoAlojamientoCreate();
            char nextOption = getUserOptionChar("\nSeguir llenando datos? y/n o 'm' para volver al menu principal.", "Escoge una opción: ");
            if(nextOption == 'y'){
                tipoAlojamientoShow(option);
            } else if(nextOption == 'm'){
                screen.start(nextOption);
            } else {
                char opt = 'c';
                tipoAlojamientoShow(opt);
            }
        }else if(option == '3'){ //Editar ciudad
            tipoAlojamientoEdit();
        }else if(option == '4'){ // eliminar ciudad
            
        }else if(option == '0'){
            char opt = 'c';
            tipoAlojamientoShow(opt);
        }else if(option == 'm'){
            screen.start(option);
        }else {
            char opt = 'c';
            tipoAlojamientoShow(opt);
        }
    }    
}
void AdminScreen::tipoAlojamientoList() {
    cleanScreen();
    TipoAlojamientoStore tipoAlojamientoStore;

    char **data = tipoAlojamientoStore.getAllTiposAlojamientos();
    int lengthData = tipoAlojamientoStore.getNumLines();

    if(data != nullptr){
        std::cout<<VERDE<<"LISTADO DE TIPOS DE ALOJAMIENTO: \n\n"<<RESET;
        for(int i = 0; i <= lengthData - 1; i++){
            std::cout << "Tipo de alojamiento :" << ": " << data[i] << std::endl;
        }
        char option = getUserOptionChar("\nAprete cualquier tecla para regresar:", "Escriba: ");

        if(option){
            option = 'c';
            tipoAlojamientoShow(option);
        }
    }else{
        std::cout<<"No hay datos Por ahora...\n";
        char option = getUserOptionChar("Desea Agregar un nuevo tipo de alomamiento? Aprete 'm' para volver al menu principal.", "Agregar tipo de alojamiento y/n: ");
        if( option == 'y'){
            tipoAlojamientoCreate();
        }else if( option == 'n'){
            option = 'c';
            tipoAlojamientoShow(option);
        } else if( option == 'm'){
            returnMainMenu();
        } else {
            tipoAlojamientoList();
        }
    }
}
void AdminScreen::tipoAlojamientoCreate() {
    cleanScreen();
    char* option = getUserOptionString("Por favor escriba el nombre del tipo de alojamiento.", "Escriba el nombre:");
    
    TipoAlojamientoStore tipoAlojamiento;
    TipoAlojamiento newTipoAlojamiento(option);

    tipoAlojamiento.addTipoAlojamiento(newTipoAlojamiento);
	delete[] option;
    
}
void AdminScreen::tipoAlojamientoEdit(){
    cleanScreen();
    TipoAlojamientoStore tipoAlojamiento;

    char **data = tipoAlojamiento.getAllTiposAlojamientos();    
    int lengthData = tipoAlojamiento.getNumLines();
    if(data != nullptr){
        std::cout<<VERDE<<"LISTADO DE TIPOS DE ALOJAMIENTO: \n\n"<<RESET;   
        for(int i = 0; i <= lengthData - 1; i++){
            std::cout << "Tipo de alojamiento :" << ": " << data[i] << std::endl;
        } 
         
        char* alojamientoById = nullptr;
        char* idOption = nullptr;
        char* name = nullptr;

        do {
            idOption = getUserOptionString("\nEscriba el id del tipo de alojamiento que va a editar.", "Escriba el id: ");
            alojamientoById = tipoAlojamiento.getTipoAlojamientoById(idOption);
            if(alojamientoById == nullptr){
                std::cout <<ROJO<< "\nID inválido. Ingrese nuevamente\n"<<RESET;
            }
        }
        while (alojamientoById == nullptr);

        if(alojamientoById != nullptr){
            char nameOption = getUserOptionChar("\nDesea editar el nombre?", "Escoge una opción y/n: ");
            if(nameOption == 'y'){
                name = getUserOptionString("Por favor escriba el nuevo nombre del tipo de alojamiento", "Escriba el nombre:");
            }             

            TipoAlojamiento editAlojamiento(name);
            bool isEdited = tipoAlojamiento.editTipoAlojamiento(idOption, editAlojamiento);
            
            delete[] name;   
            delete[] idOption; 
            
            if(isEdited){
                std::cout<<VERDE<<"\nTipo de Alojamiento Editado con éxito\n"<<RESET;
                char nextOption = getUserOptionChar("\nQuiere editar otro tipo de alojamiento?.", "Escoge una opción y/n: ");
                if(nextOption == 'y'){
                    tipoAlojamientoEdit();
                }else if(nextOption == 'n'){
                    nextOption = 'c';
                    tipoAlojamientoShow(nextOption);
                } else {
                    tipoAlojamientoEdit();
                }
            }else{
                std::cout<<ROJO<<"\nNo se pudo editar!\n"<<RESET;
                char nextOption = getUserOptionChar("\nQuiere volver a intentarlo?.", "Escoge una opción y/n: ");
                if(nextOption == 'y'){
                    tipoAlojamientoEdit();
                }else if(nextOption == 'n'){
                    nextOption = 'c';
                    tipoAlojamientoShow(nextOption);
                } else {
                    tipoAlojamientoEdit();
                }
            }

        }

        delete[] alojamientoById;

        

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

//Alojamientos
void AdminScreen::alojamientoShow(char &option){
    cleanScreen();
    char getOption;
    ScreenView screen;
    if(option == 'c'){
        getOption = getUserOptionChar("Módulo de alojamientos. Por favor escoja una de las opciones, o aprete '0' para retroceder o 'm' para ver el menú principal.\n1) Listar todos los tipos de alojamientos\n2) Crear nuevo tipo de alojamiento\n3) Editar tipo de alojamiento\n4) Eliminar tipo de alojamiento\n", "Escoge una opción: ");
        cityShow(getOption);
    }else {
        if(option == '1'){ //Listar ciudad
            cityList();               
        }else if(option == '2'){ //Crear ciudad
            cityCreate();
            char nextOption = getUserOptionChar("\nSeguir llenando datos? y/n o 'm' para volver al menu principal.", "Escoge una opción: ");
            if(nextOption == 'y'){
                cityShow(option);
            } else if(nextOption == 'm'){
                screen.start(nextOption);
            } else {
                menuAdminShow();
            }

        }else if(option == '3'){ //Editar ciudad
            cityEdit();
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