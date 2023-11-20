#include "./User.h"
#pragma once

class Host : public User {
public:
    Host(const char* email, const char* name, const char* password);
    
    void permisos() override;
};