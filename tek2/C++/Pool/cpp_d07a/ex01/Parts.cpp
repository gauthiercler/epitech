/*
** Parts.cpp for cpp_d07m in /home/gogo/rendu/tek2/cpp_d07a/ex01/Parts.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 10 18:55:14 2017 Gauthier CLER
** Last update Tue Jan 10 18:55:14 2017 Gauthier CLER
*/


#include <algorithm>
#include <iostream>
#include "Parts.h"

Arms::Arms(const std::string &serial, bool functionnal) {
  this->_serial = serial;
  this->_functionnal = functionnal;
}

Arms::~Arms() {


}

bool Arms::isFunctionnal() const {
  return this->_functionnal;
}

std::string Arms::serial() const {
  return this->_serial;
}

void Arms::informations()  const{
  std::cout << "\t[Parts] " << "Arms " << this->_serial << " status : " << ((this->_functionnal) ? "OK" : "KO") << std::endl;
}

Legs::Legs(const std::string &serial, bool functionnal) {
  this->_serial = serial;
  this->_functionnal = functionnal;
}

Legs::~Legs() {

}

bool Legs::isFunctionnal() const{
  return this->_functionnal;
}

std::string Legs::serial() const{
  return this->_serial;
}

void Legs::informations() const{
  std::cout << "\t[Parts] " << "Legs " << this->_serial << " status : " << ((this->_functionnal) ? "OK" : "KO") << std::endl;
}

Head::Head(const std::string &serial, bool functionnal) {
  this->_serial = serial;
  this->_functionnal = functionnal;
}

Head::~Head() {

}

bool Head::isFunctionnal() const{
  return this->_functionnal;
}

std::string Head::serial() const{
  return this->_serial;
}

void Head::informations()  const{
  std::cout << "\t[Parts] " << "Head " << this->_serial << " status : " << ((this->_functionnal) ? "OK" : "KO") << std::endl;
}
