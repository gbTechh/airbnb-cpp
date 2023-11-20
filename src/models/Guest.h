#include "./User.h"
#pragma once

class Guest : public User {
public:
    Guest(const char* email, const char* name, const char* password);
    
    void permisos() override;
};