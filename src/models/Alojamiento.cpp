#include "./Alojamiento.h"

Alojamiento::Alojamiento(const char* _name, const char* _description, const char* _idTipoAlojamiento, const char* _idCity, const char* _idHost, const float _priceNigth) {   
  name = new char[strlen(_name) + 1];
  strcpy(name, _name);

  description = new char[strlen(_description) + 1];
  strcpy(description, _description);

  idTipoAlojamiento = new char[strlen(_idTipoAlojamiento) + 1];
  strcpy(idTipoAlojamiento, _idTipoAlojamiento);

  idCity = new char[strlen(_idCity) + 1];
  strcpy(idCity, _idCity);

  idHost = new char[strlen(_idHost) + 1];
  strcpy(idHost, _idHost);

  priceNigth = _priceNigth;
}

Alojamiento::Alojamiento(){}

Alojamiento::~Alojamiento() {
  // delete[] name;
  // delete[] description;
  // delete[] idTipoAlojamiento;
  // delete[] idCity;
  // delete[] idHost;
}

const char* Alojamiento::getName() const {
  return name;
}
void Alojamiento::setName(const char* name) {
  delete[] this->name;
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
}

const char* Alojamiento::getDescription() const {
  return description;
}
void Alojamiento::setDescription(const char* description) {
  delete[] this->description;
  this->description = new char[strlen(description) + 1];
  strcpy(this->description, description);
}

const char* Alojamiento::getIdTipoAlojamiento() const {
  return idTipoAlojamiento;
}
void Alojamiento::setIdTipoAlojamiento(const char* idTipoAlojamiento) {
  delete[] this->idTipoAlojamiento;
  this->idTipoAlojamiento = new char[strlen(idTipoAlojamiento) + 1];
  strcpy(this->idTipoAlojamiento, idTipoAlojamiento);
}

const char* Alojamiento::getIdCity() const {
  return idCity;
}
void Alojamiento::setIdCity(const char* idCity) {
  delete[] this->idCity;
  this->idCity = new char[strlen(idCity) + 1];
  strcpy(this->idCity, idCity);
}

const char* Alojamiento::getIdHost() const {
  return idHost;
}
void Alojamiento::setIdHost(const char* idHost) {
  delete[] this->idHost;
  this->idHost = new char[strlen(idHost) + 1];
  strcpy(this->idHost, idHost);
}

const float Alojamiento::getPriceNigth() const {
  return priceNigth;
}
void Alojamiento::setPriceNigth(const float priceNigth) {
  this->priceNigth =  priceNigth;
}