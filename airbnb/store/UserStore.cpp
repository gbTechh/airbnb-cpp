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
    char* adminEmail = new char[17];
    strcpy(adminEmail, "admin@gmail.com");
    bool existsAdmin =  getUserByEmail(adminEmail);
    if(existsAdmin){
        // std::cout<<"Ya existe el admin";
    }else{
        User newUser(adminEmail, "admin", "administrador001");
        addUser(newUser);    
    }
}

void UserStore::addUser(const User& user) {
    int rowIndex = numUsers + 1;
	int longChar = 256;
    char* userInfo = new char[longChar];
	
    std::snprintf(userInfo, longChar, "%d;%s", rowIndex, user.getName(), user.getEmail(), user.getPassword(), user.getTipoUsuario());
    insertData(userInfo);
    
    delete[] userInfo;
    numUsers++;
}

char** UserStore::getAllUsers() {
    return getAllData();
}

char* UserStore::getUserByEmail(char* email) {
	char** data = getAllData();
	int count = 0;
    char* user = new char[17];
    strcpy(user, "admin@gmail.com");
	while (data != nullptr && data[count] != nullptr) {
		count++;
        String userStr(data[count]);
        bool existsEmail = userStr.includes(email);
		if(existsEmail){
            strcpy(user, data[count]);
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


