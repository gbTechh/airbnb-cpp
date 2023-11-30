#include <iostream>
#include <fstream>
#include <cstring>
#include "UserStore.h"
#include "../models/User.h"
#include "../helpers/String.h"
#include "./Store.h"

UserStore::UserStore() : Store("../src/database/files/users.txt"), users(nullptr), numUsers(0) {
    std::ifstream file(filename);

    if (file) {
        numUsers = getNumLinesOfFile();
    }
}

void UserStore::createAdmin(){
    char* adminEmail = new char[16];
    strcpy(adminEmail, "admin@gmail.com");
    char* existsAdmin =  getUserByEmail(adminEmail);
    bool isNull = existsAdmin == nullptr;
    if(isNull){
        User newUser(adminEmail, "admin", "administrador001");
        newUser.setTipoUsuario(0);
        addUser(newUser);    
    }
}

void UserStore::addUser(const User& user) {
    int rowIndex = numUsers + 1;
	int longChar = 256;
    char* userInfo = new char[longChar];
    std::snprintf(userInfo, longChar, "%d;%s;%s;%s;%s", rowIndex, user.getName(), user.getEmail(), user.getPassword(), user.getTipoUsuario());
    insertData(userInfo);
    
    delete[] userInfo;
    numUsers++;
}

char** UserStore::getAllUsers() {
    return getAllData();
}

char* UserStore::getUserByEmail(char* email) {
	char** data = getAllData();
    char* user = nullptr;
    bool include = false;
    int count = 0;

    for(int i= 0; i <= numLines - 1; i++){
        if(!include){
            char* line = data[i];
            String userStr(line);
            include = userStr.includes(email);
            if(include){
                user = new char[strlen(line) + 1];
                strcpy(user, line);
            }
        }
    }
  
	return user;
}

char** UserStore::getAllUsersById() {
    char **data = getAllData();
    int count = 0;

    while (data[count] != nullptr) {
        // std::cout << "Pais" << ": " << data[count] << std::endl;
        count++;
        // char* ptr = data[count];

        // while (*ptr != ';') { 
        //     char currentChar = *ptr; 
            
        //     std::cout << currentChar << std::endl;
        //     ptr++;
        // }
        // while(data[count] == ';'){
        //     std::cout<<"detener";
        // }
        char* token = std::strtok(data[count], ";");
        while (token != nullptr) {
            std::cout << token << std::endl;
            token = std::strtok(nullptr, ";");
        }
    }
    return data;
}

bool UserStore::authUser(char* email, char* password, const char* rol){
    char* user = getUserByEmail(email);


    if(user == nullptr){
        return false;
    } else{
        char separator = ';';
        String str(user);
        char** res = str.split(separator);
        
        char* passAuth = res[3];
        char* rolAuth = res[4];
        int isSamePassword = std::strcmp(passAuth, password);
        int isSameRol = std::strcmp(rolAuth, rol);
     
        if(isSamePassword == 0){
            if(isSameRol == 0){
                return true;
            } else {
                return false;
            }
        } else{
            return false;
        }
    }
                   
}