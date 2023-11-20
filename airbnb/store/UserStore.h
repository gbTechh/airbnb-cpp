#pragma once
#include "../models/User.h"
#include "./Store.h"

class UserStore: public Store {
public:
    UserStore();
    void addUser(const User& user);
    void createAdmin();
    char** getAllUsers();
    char** getAllUsersById();
    char* getUserByEmail(char* email);

private:
    User* users;
    int numUsers;
};