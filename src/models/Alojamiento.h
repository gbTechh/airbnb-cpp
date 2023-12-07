#pragma once
#include <iostream>
#include <cstring>

class Alojamiento {
public:
    Alojamiento(const char* name, const char* description, const char* idTipoAlojamiento, const char* idCity, const char* idHost, const float priceNigth);
    Alojamiento();
    ~Alojamiento();
    const char* getName() const;   
    void setName(const char* name);
    const char* getDescription() const;   
    void setDescription(const char* description);
    const char* getIdTipoAlojamiento() const;   
    void setIdTipoAlojamiento(const char* idTipoAlojamiento);
    const char* getIdCity() const;   
    void setIdCity(const char* idCity);
    const char* getIdHost() const;   
    void setIdHost(const char* idHost);
    const float getPriceNigth() const;   
    void setPriceNigth(const float idHost);

private:
    char* name;
    char* description;
    char* idTipoAlojamiento;
    char* idCity;
    char* idHost;
    float priceNigth;
    int id;
};