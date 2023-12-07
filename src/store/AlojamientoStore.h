#pragma once
#include "../models/Alojamiento.h"
#include "./Store.h"
#include "../helpers/String.h"

class AlojamientoStore: public Store {
public:
    AlojamientoStore();
    void addAlojamiento(const Alojamiento& Alojamiento);
    char** getAllAlojamientos();
    char* getAlojamientoById(char* id);
    bool editAlojamiento(char* id, const Alojamiento& Alojamiento);

private:
    Alojamiento* alojamientos;
    int numAlojamientos;
};