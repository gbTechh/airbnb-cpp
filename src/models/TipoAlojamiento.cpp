#include "./TipoAlojamiento.h"

TipoAlojamiento::TipoAlojamiento(const char* name) {   
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
}

TipoAlojamiento::~TipoAlojamiento() {
  delete[] name;
}

const char* TipoAlojamiento::getName() const {
  return name;
}

void TipoAlojamiento::setName(const char* name) {
  delete[] this->name;
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
}