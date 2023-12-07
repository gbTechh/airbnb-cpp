#pragma once
#include <iostream>
#include <cstring>

class TipoAlojamiento {
public:
    TipoAlojamiento(const char* name);
    TipoAlojamiento();
    ~TipoAlojamiento();
    const char* getName() const;   
    void setName(const char* name);

private:
    char* name;
    int id;
};