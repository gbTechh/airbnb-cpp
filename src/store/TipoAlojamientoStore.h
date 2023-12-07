#pragma once
#include "../models/TipoAlojamiento.h"
#include "./Store.h"
#include "../helpers/String.h"

class TipoAlojamientoStore: public Store {
public:
    TipoAlojamientoStore();
    void addTipoAlojamiento(const TipoAlojamiento& tipoAlojamiento);
    char** getAllTiposAlojamientos();
    char* getTipoAlojamientoById(char* id);
    bool editTipoAlojamiento(char* id, const TipoAlojamiento& tipoAlojamiento);

private:
    TipoAlojamiento* tiposAlojamientos;
    int numTiposAlojamientos;
};