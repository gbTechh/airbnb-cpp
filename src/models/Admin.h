#include "./User.h"
#pragma once

class Admin : public User {
public:
    Admin(const char* email, const char* name, const char* password);
    
    void permisos() override;
};