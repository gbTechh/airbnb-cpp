#include <iostream>
#include "./baseScreen.h"
#include "../components/input.h"
#include "../screenView.h"

BaseScreen::BaseScreen() {}

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

void BaseScreen::returnMainMenu(){
  ScreenView screen;
  char option = 'm';
  screen.start(option);
}