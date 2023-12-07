#include <iostream>
#include <cstring>
#include "./baseScreen.h"
#include "../components/input.h"
#include "../screenView.h"
#include "../helpers/String.h"

BaseScreen::BaseScreen() {}
BaseScreen::~BaseScreen() {
 
}

void BaseScreen::cleanScreen() {
  system("clear");
}

void BaseScreen::show() {}

char BaseScreen::getUserOptionChar(const char* message, const char* label = "Escoja una opción: ") {
  std::cout << message;
  Input inputComponent(label);
  char option = inputComponent.displayChar();
  
  return option;
}
int BaseScreen::getUserOptionInt(const char* message, const char* label = "Escoja una opción: ") {
  std::cout << message;
  Input inputComponent(label);
  int option = inputComponent.displayInt();
  
  return option;
}
char* BaseScreen::getUserOptionString(const char* message, const char* label = "Introduzca: ") {
  std::cout << message;
  Input inputComponent(label);
  char* option = inputComponent.displayString();
  
  return option;
}

float BaseScreen::getUserOptionFloat(const char* message, const char* label = "Introduzca: ") {
  std::cout << message;
  Input inputComponent(label);
  float option = inputComponent.displayFloat();

  return option;
}

void BaseScreen::returnMainMenu(){
  ScreenView screen;
  char option = 'm';
  screen.start(option);
}

void BaseScreen::setCurrentUser(const char* user){
  currentUser = new char[strlen(user) + 1];
  strcpy(currentUser, user);
}

char* BaseScreen::getNameCurrentUser() const{
  String user(currentUser);
  char separator = ';';
  char** dataUser = user.split(separator);

  char* nameUser = new char[strlen(dataUser[1]) + 1];
  strcpy(nameUser, dataUser[1]);

  delete[] dataUser;
  return nameUser;
}

char* BaseScreen::getIdCurrentUser() const{
  String user(currentUser);
  char separator = ';';
  char** dataUser = user.split(separator);

  char* idUser = new char[strlen(dataUser[0]) + 1];
  strcpy(idUser, dataUser[0]);

  delete[] dataUser;
  return idUser;
}