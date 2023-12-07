#include <iostream>
#include "./hostScreen.h"
#include "../components/input.h"
#include "../screenView.h"
#include "../store/UserStore.h"
#include "../store/AlojamientoStore.h"
#include "../store/TipoAlojamientoStore.h"
#include "../store/CityStore.h"
#include "../models/Alojamiento.h"
#include "../models/User.h"
#include "../colors.h"
#include "./baseScreen.h"
#include "../helpers/String.h"

HostScreen::HostScreen() {}

void HostScreen::show() {
    initFilesScreen();
    cleanScreen();
    loginScreen();
}

void HostScreen::initFilesScreen() {
    AlojamientoStore alojamientoStore;
    alojamientoStore.createFile();

    CityStore cityStore;
    cityStore.createFile();

    TipoAlojamientoStore tipoAlojamientoStore;
    tipoAlojamientoStore.createFile();

    UserStore userStore;
    userStore.createFile();

}

void HostScreen::loginScreen() {
    cleanScreen();
    std::cout<<VERDE<<"Pantalla de Host\n"<<RESET;
    char option = getUserOptionChar("Bienvenido Host, por favor escoja una de las opciones, aprete m para ver el menú principal.\n\n1) Iniciar sesión\n", "Escoge una opción");

    if (option == '1') {
        loginShow();
    } else if (option == 'm') {
        returnMainMenu();
    } else {
        loginScreen();
    }    
}

//Show screens
void HostScreen::loginShow() {
    cleanScreen();
    std::cout<<VERDE<<"Iniciar Sesión como HOST\n"<<RESET;
    char option = getUserOptionChar("Esta a punto de iniciar sesión. Aprete 'y' para continuar 'n' para regresar o 'm' para ver el menú principal.\n", "Continuar y/n");
    if (option == 'y') {
        Input inputUsername("Escriba su email: ");
        char* username = inputUsername.displayString();
        Input inputPassword("Escriba su password: ");
        char* password = inputPassword.displayString();
        UserStore user;

        char* rol = "host";
        char* userAuth = user.authUser(username, password, rol);

        delete[] username;
        delete[] password;

        if(userAuth == nullptr){
            loginShow();    
        }else{
            setCurrentUser(userAuth);
            menuHostShow();
        }
    } else if (option == 'n') {
        loginScreen();
    } else if(option == 'm'){
        returnMainMenu();
    } else {
        loginShow();
    }   
    
}
void HostScreen::menuHostShow() { 
    cleanScreen();
    char* currentUser = getNameCurrentUser();

    std::cout<<VERDE<<"Bienvenido Usuario: "<<MAGENTA<<currentUser<<"\n\n"<<RESET;
    char option = getUserOptionChar("Por favor escoja una de las opciones, o aprete '0' para salir de host o 'm' para ver el menú principal.\n\n1) Gestionar alojamientos\n2) Gestionar Reservas\n3) Gestionar Mensajes\n4) Gestionar Reseñas\n0) Salir de host\n", "Escoge una opción: ");

    delete[] currentUser;

    if(option == '1'){
        char opt = 'c';
        alojamientoShow(opt); 
    }else if(option == '2'){
        char opt = 'c';
        
    }else if(option == '3'){
        
    }else if(option == '4'){
        
    }else if(option == '0'){
        loginScreen();
    }else if(option == 'm'){
        returnMainMenu();
    }else {
        menuHostShow();
    }

}

//Alojamientos
void HostScreen::alojamientoShow(char &option) {
    cleanScreen();
    char getOption;
    if(option == 'c'){
        getOption = getUserOptionChar("Módulo de alojamientos. Por favor escoja una de las opciones, o aprete '0' para retroceder o 'm' para ver el menú principal.\n\n\n1) Listar tus alojamientos\n2) Crear nuevo alojamiento\n3) Editar Alojamiento\n4) Eliminar Alojamiento\n0) Retroceder\nm) Volver al menu principal\n", "Escoge una opción: ");
        alojamientoShow(getOption);
    }else {
        if(option == '1'){ //Listar pais
            alojamientoList();               
        }else if(option == '2'){ //Crear pais
            alojamientoCreate();
            char nextOption = getUserOptionChar("Seguir llenando datos? y/n o 'm' para volver al menu principal.", "Escoge una opción: ");
            if(nextOption == 'y'){
                alojamientoShow(option);
            } else if(nextOption == 'm'){
                returnMainMenu();
            } else {
                menuHostShow();
            }

        }else if(option == '3'){ //Editar pais
            // countryEdit();
        }else if(option == '4'){ // eliminar Pais
            
        }else if(option == '0'){
            menuHostShow();
        }else if(option == 'm'){
            returnMainMenu();
        }else {
            char opt = 'c';
            alojamientoShow(opt);
        }
    }
}

void HostScreen::alojamientoList() {
    cleanScreen();
    AlojamientoStore alojamientoStore;

    char **data = alojamientoStore.getAllAlojamientos();
    int lengthData = alojamientoStore.getNumLines();

    if(data != nullptr){
        std::cout<<VERDE<<"LISTADO DE TUS ALOJAMIENTOS: \n\n"<<RESET;
        for(int i = 0; i <= lengthData - 1; i++){
            std::cout << "Alojamiento ->"<< data[i] << std::endl;
        }
       
        char option = getUserOptionChar("\nAprete cualquier tecla para regresar:", "Escriba: ");

        if(option){
            option = 'c';
            alojamientoShow(option);
        }
    }else{
        std::cout<<"No hay datos Por ahora...\n";
        char option = getUserOptionChar("Desea Agregar un alojamiento? Aprete 'm' para volver al menu principal.", "Agregar alojamiento y/n: ");
        if( option == 'y'){
            alojamientoCreate();
        }else if( option == 'n'){
            option = 'c';
            alojamientoShow(option);
        } else if( option == 'm'){
            returnMainMenu();
        } else {
            alojamientoList();
        }
    }
}

void HostScreen::alojamientoCreate() {
    cleanScreen();
    std::cout<<VERDE<<"Agregar un alojamiento:\n\n"<<RESET;
    char* name = getUserOptionString("Por favor escriba el nombre del alojamiento.", "Escriba el nombre:");    
    char* description = getUserOptionString("Por favor escriba la descripcion del alojamiento.(Presione Enter)", "Escriba la descripcion:");  

    //AGREGAR ID ALOJAMIENTO
    TipoAlojamientoStore tipoAlojamientoStore;
    char **dataAlojamientos = tipoAlojamientoStore.getAllTiposAlojamientos();
    int lengthDataAlojamiento = tipoAlojamientoStore.getNumLines();
    
    char* idTipoAlojamiento = nullptr;

    if(dataAlojamientos != nullptr){
        std::cout<<VERDE<<"\n\nLISTADO DE TIPOS DE ALOJAMIENTO: \n\n"<<RESET;
        for(int i = 0; i <= lengthDataAlojamiento - 1; i++){
            std::cout << "Tipo de alojamiento :" << ": " << dataAlojamientos[i] << std::endl;
        }

        std::cout<<"\n";
        do {
            char* idOption = getUserOptionString("Por favor escriba el Id del tipo de alojamiento.(Presione Enter)", "Escriba el ID:");    
            idTipoAlojamiento = tipoAlojamientoStore.getTipoAlojamientoById(idOption);
            if(idTipoAlojamiento == nullptr){
                std::cout <<ROJO<< "\nID inválido. Ingrese nuevamente\n"<<RESET;
            }
            delete[] idOption;
        }
        while(idTipoAlojamiento == nullptr);
    }

    //AGREGAR ID CIUDAD
    CityStore cityStore;
    char **dataCities = cityStore.getAllCities();
    int lengthDataCities = cityStore.getNumLines();

    char* idCity = nullptr;

    if(dataCities != nullptr){
        std::cout<<VERDE<<"\n\nLISTADO DE TIPOS DE CIUDADES: \n\n"<<RESET;
        for(int i = 0; i <= lengthDataCities - 1; i++){
            std::cout << "Ciudades :" << ": " << dataCities[i] << std::endl;
        }
        std::cout<<"\n";
        do {
            char* idOption = getUserOptionString("Por favor escriba el Id de la ciudad.(Presione Enter)", "Escriba el ID:");    
            idCity = cityStore.getCityById(idOption);
            if(idCity == nullptr){
                std::cout <<ROJO<< "\nID inválido. Ingrese nuevamente\n"<<RESET;
            }
            delete[] idOption;
        }
        while(idCity == nullptr);
    }
   
    char* idHost = getIdCurrentUser();
       
    float price = getUserOptionFloat("Por favor escriba el precio por noche.(Presione Enter)", "Escriba el precio:");
    AlojamientoStore alojamientoStore;

    char separator = ';';
    
    String idTipoAloj(idTipoAlojamiento);
    char** arrDataTipoAloj = idTipoAloj.split(separator);        
    char* idTipoAlojNew = arrDataTipoAloj[0];

    String idCityStr(idCity);
    char** arrDatacity = idCityStr.split(separator);        
    char* idCityNew = arrDatacity[0];
    
    Alojamiento newAlojamiento(name, description, idTipoAlojNew, idCityNew, idHost,price);

    alojamientoStore.addAlojamiento(newAlojamiento);
	delete[] name;
	delete[] description;
	delete[] idTipoAlojamiento;
	delete[] idCity;
	delete[] idHost;
	delete[] dataAlojamientos;
	delete[] dataCities;

	delete[] arrDataTipoAloj;
	delete[] idTipoAlojNew;

	delete[] arrDatacity;
	delete[] idCityNew;
    
}