#include <iostream>
#include <string>
#include "./guestScreen.h"
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
#include "../helpers/ArrayStr.h"

GuestScreen::GuestScreen() {}

void GuestScreen::show() {
    initFilesScreen();
    cleanScreen();
    menuGuestShow();
}

void GuestScreen::initFilesScreen() {
    AlojamientoStore alojamientoStore;
    alojamientoStore.createFile();

    CityStore cityStore;
    cityStore.createFile();

    TipoAlojamientoStore tipoAlojamientoStore;
    tipoAlojamientoStore.createFile();

    UserStore userStore;
    userStore.createFile();

}

void GuestScreen::loginScreen() {
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
void GuestScreen::loginShow() {
    cleanScreen();
    std::cout<<VERDE<<"Iniciar Sesión como HOST\n"<<RESET;
    char option = getUserOptionChar("Esta a punto de iniciar sesión. Aprete 'y' para continuar 'n' para regresar o 'm' para ver el menú principal.\n", "Continuar y/n");
    if (option == 'y') {
        Input inputUsername("Escriba su email: ");
        char* username = inputUsername.displayString();
        Input inputPassword("Escriba su password: ");
        char* password = inputPassword.displayString();
        UserStore user;

        const char* rol = "host";
        char* userAuth = user.authUser(username, password, rol);

        delete[] username;
        delete[] password;

        if(userAuth == nullptr){
            loginShow();    
        }else{
            setCurrentUser(userAuth);
            menuGuestShow();
        }
    } else if (option == 'n') {
        loginScreen();
    } else if(option == 'm'){
        returnMainMenu();
    } else {
        loginShow();
    }   
    
}
void GuestScreen::menuGuestShow() { 
    cleanScreen();

    std::cout<<VERDE<<"Bienvenido Usuario Guest:\n\n"<<RESET;
    char option = getUserOptionChar("Por favor escoja una de las opciones, o aprete '0' para salir de esta pantalla o 'm' para ver el menú principal.\n\n1) Buscar alojamientos\n2) Realizar una reserva Reservas\n0) Salir de host\n", "Escoge una opción: ");

    if(option == '1'){
        findAlojamientoShow(); 
    }else if(option == '2'){
        char opt = 'c';
        // reserveAlojamientoShow(opt);  
    }else if(option == '0'){
        returnMainMenu();
    }else if(option == 'm'){
        returnMainMenu();
    }else {
        menuGuestShow();
    }

}

void GuestScreen::findAlojamientoShow(){
    cleanScreen();
    std::cout<<VERDE<<"Sección de búsqueda. Buscar por:\n\n"<<RESET;   
    char option = getUserOptionChar("Por favor escoja una de las opciones, o aprete '0' para salir de esta pantalla o 'm' para ver el menú principal.\n\n1) Por ciudad\n2) Por nombre\n3) Por precio\n4) Por tipo de alojamiento\n0) Salir de host\n", "Escoge una opción: ");

    if(option == '1'){
        findByCity(); 
        char option = getUserOptionChar("\n\nDesea seguir buscando?.", "Seguir buscando y/n: ");
        if(option == 'y'){
            findAlojamientoShow();
        }else {
            menuGuestShow();
        }
    }else if(option == '2'){
        findByName();
        char option = getUserOptionChar("\n\nDesea seguir buscando?.", "Seguir buscando y/n: ");
        if(option == 'y'){
            findAlojamientoShow();
        }else {
            menuGuestShow();
        }
    }else if(option == '3'){
        findByPrice(); 
        char option = getUserOptionChar("\n\nDesea seguir buscando?.", "Seguir buscando y/n: ");
        if(option == 'y'){
            findAlojamientoShow();
        }else {
            menuGuestShow();
        }
    }else if(option == '4'){
        findByType();
        char option = getUserOptionChar("\n\nDesea seguir buscando?.", "Seguir buscando y/n: ");
        if(option == 'y'){
            findAlojamientoShow();
        }else {
            menuGuestShow();
        }
    }else if(option == '0'){
        returnMainMenu();
    }else if(option == 'm'){
        returnMainMenu();
    }else {
        findAlojamientoShow();
    }
}

ArrayStr GuestScreen::getAllAlojamientosBySomeId(int index, char* id){
    AlojamientoStore alojamientoStore;

    char **data = alojamientoStore.getAllAlojamientos();
    int lengthData = alojamientoStore.getNumLines();
    ArrayStr arrAlojamientos;
    char separator = ';';

    if(data != nullptr){        
        for(int i = 0; i <= lengthData - 1; i++){
            String line(data[i]);
            char** arrData = line.split(separator);        
            char* idData = arrData[index];
            int isSameId = std::strcmp(idData, id);
            if(isSameId == 0){
                arrAlojamientos.push(data[i]);
            }
        }   
    }

    return arrAlojamientos;
}

void GuestScreen::findByCity(){
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

        do {
            idOption = getUserOptionString("\nEscriba el id de la ciudad por la cual quiere buscar.", "Escriba el id: ");
            cityById = cityStore.getCityById(idOption);
            if(cityById == nullptr){
                std::cout <<ROJO<< "\nID inválido. Ingrese nuevamente\n"<<RESET;
            }
        }
        while (cityById == nullptr);

        if(cityById != nullptr){   
            ArrayStr cityArray = getAllAlojamientosBySomeId(4,idOption);
            for (int i = 0; i < cityArray.getLength(); ++i) {
                formatterAlojamiento(cityArray.getIndex(i));
            }

        }       

    }else {
        std::cout<<"No hay datos Por ahora...\n";
        char option = getUserOptionChar("Aprete '0' para salir o 'm' para vovler al menu principal.", "Escoge una opción 0/m: ");
        if( option == 'n'){
            findAlojamientoShow();
        } else if( option == 'm'){
            returnMainMenu();
        } else {
            menuGuestShow();
        }
    }
}

void GuestScreen::findByType(){
    TipoAlojamientoStore tipoAlojamientoStore;

    char **data = tipoAlojamientoStore.getAllTiposAlojamientos();
    int lengthData = tipoAlojamientoStore.getNumLines();

    if(data != nullptr){
        std::cout<<VERDE<<"LISTADO DE TIPOS DE ALOJAMIENTO: \n\n"<<RESET;   
        for(int i = 0; i <= lengthData - 1; i++){
            std::cout << "Tipo de alojamiento :" << ": " << data[i] << std::endl;
        }          
        char* tipoAlojById = nullptr;
        char* idOption = nullptr;

        do {
            idOption = getUserOptionString("\nEscriba el id del tipo de alojamiento por el cual quiere buscar.", "Escriba el id: ");
            tipoAlojById = tipoAlojamientoStore.getTipoAlojamientoById(idOption);
            if(tipoAlojById == nullptr){
                std::cout <<ROJO<< "\nID inválido. Ingrese nuevamente\n"<<RESET;
            }
        }
        while (tipoAlojById == nullptr);

        if(tipoAlojById != nullptr){       
            ArrayStr cityArray = getAllAlojamientosBySomeId(3,idOption);
            for (int i = 0; i < cityArray.getLength(); ++i) {
                formatterAlojamiento(cityArray.getIndex(i));
            }
        }       

    }else {
        std::cout<<"No hay datos Por ahora...\n";
        char option = getUserOptionChar("Aprete '0' para salir o 'm' para vovler al menu principal.", "Escoge una opción 0/m: ");
        if( option == 'n'){
            findAlojamientoShow();
        } else if( option == 'm'){
            returnMainMenu();
        } else {
            menuGuestShow();
        }
    }
}

void GuestScreen::findByPrice(){
    std::cout<<VERDE<<"Busqueda por precio \n\n"<<RESET;  

    float priceMinInput = getUserOptionFloat("Por favor escriba el precio minimo", "Precio minimo:");
    float priceMaxInput = getUserOptionFloat("Por favor escriba el precio maximo", "Precio maximo:");

    AlojamientoStore alojamientoStore;

    char **data = alojamientoStore.getAllAlojamientos();
    int lengthData = alojamientoStore.getNumLines();
    ArrayStr arrAlojamientos;
    char separator = ';';

    if(data != nullptr){        
        for(int i = 0; i <= lengthData - 1; i++){
            String line(data[i]);
            char** arrData = line.split(separator);        
            char* priceData = arrData[6];
            float priceFloat = std::stof(priceData);

            if(priceFloat <= priceMaxInput && priceFloat >= priceMinInput){
                arrAlojamientos.push(data[i]);
            }
        }   
    }

    for (int i = 0; i < arrAlojamientos.getLength(); ++i) {
        formatterAlojamiento(arrAlojamientos.getIndex(i));
    }

}

void GuestScreen::findByName(){
    std::cout<<VERDE<<"Busqueda por nombre:\n\n"<<RESET; 
    char* nameInput = getUserOptionString("\nEscriba algun nombre por el cual quiere buscar.", "Escriba el nombre: ");

    AlojamientoStore alojamientoStore;

    char **data = alojamientoStore.getAllAlojamientos();
    int lengthData = alojamientoStore.getNumLines();
    ArrayStr arrAlojamientos;
    bool include = false;
    if(data != nullptr){        
        for(int i = 0; i <= lengthData - 1; i++){
            String line(data[i]);
            include = line.includes(nameInput);   
            
            if(include){
                arrAlojamientos.push(data[i]);
            }
        }   
    }

    for (int i = 0; i < arrAlojamientos.getLength(); ++i) {
        formatterAlojamiento(arrAlojamientos.getIndex(i));        
    }
}

void GuestScreen::formatterAlojamiento(const char* text){
    CityStore cityStore;
    TipoAlojamientoStore tipoAlojStore;

    String item(text);
    char separator = ';';
    char** arrData = item.split(separator);        
    char* id = arrData[0];
    char* name = arrData[1];
    char* desc = arrData[2];
    char* idTipoAloj = arrData[3];
    char* idCity = arrData[4];
    char* idHost = arrData[5];
    char* price = arrData[6];

    char* dataCity = cityStore.getCityById(idCity);
    String cityStr(dataCity);
    char** arrDataCity = cityStr.split(separator);    
    char* nameCity = arrDataCity[2];   

    char* dataTipoAloj = tipoAlojStore.getTipoAlojamientoById(idTipoAloj);
    String tipoAlojStr(dataTipoAloj);
    char** arrDataTipoAloj = tipoAlojStr.split(separator);    
    char* nameTipoAloj = arrDataTipoAloj[1];    
    


    std::cout<<"Id::"<<AMARILLO<<id<<RESET" | "<<"Nombre::"<<AMARILLO<<name<<RESET<<" | "<<"Ciudad::"<<AMARILLO<<nameCity<<RESET<<" | "<<"Precio::"<<AMARILLO<<price<<RESET<<" | "<<"Tipo::"<<AMARILLO<<nameTipoAloj<<RESET<<"\n";
    std::cout<<"::"<<desc<<"\n\n";

    
    delete[] arrData;
    
    delete[] id;
    delete[] name;
    delete[] desc;
    delete[] idTipoAloj;
    delete[] idCity;
    delete[] idHost;
    delete[] price;
    delete[] dataCity;
    delete[] arrDataCity;
    delete[] nameCity;
    delete[] dataTipoAloj;
    delete[] arrDataTipoAloj;
    delete[] nameTipoAloj;
}

// void GuestScreen::reserveAlojamientoShow(char &option){

// }
