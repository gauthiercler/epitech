/*
** Toy.cpp for cpp_d09 in /home/gogo/rendu/tek2/cpp_d13/ex00/Toy.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jan 16 09:33:11 2017 Gauthier CLER
** Last update Mon Jan 16 09:33:12 2017 Gauthier CLER
*/


#include <iostream>
#include "Toy.h"

Toy::Toy() : _type(BASIC_TOY), _name(""){
  this->_picture =  new Picture();
}

Toy::Toy(const ToyType type, std::string name, std::string fileName): _type(type), _name(name){
  this->_picture = new Picture(fileName);
  this->_error.setWhere("");
  this->_error.setWhat("");
  this->_error.setErrorType(Toy::Error::UNKNOWN);
}

Toy::Toy(const Toy &toy): _type(toy.getType()), _name(toy.getName()), _picture(new Picture(*_picture)){
  this->_error.setWhere(toy._error.getWhere());
  this->_error.setWhat(toy._error.getWhat());
  this->_error.setErrorType(toy._error.getErrorType());
}

Toy::~Toy() {
  if (this->_picture != NULL)
    delete this->_picture;
}

std::string Toy::getName() const{
  return this->_name;
}

void Toy::setName(std::string name) {
  this->_name = name;
}

bool Toy::setAscii(std::string name) {
  if (!this->_picture->getPictureFromFile(name)){
    this->_error.setWhere("setAscii");
    this->_error.setWhat("bad new illustration");
    this->_error.setErrorType(Toy::Error::PICTURE);
    return false;
  }
  return true;
}

std::string Toy::getAscii() const{
  return this->_picture->data;
}

Toy::ToyType Toy::getType() const {
  return this->_type;
}

Toy &Toy::operator=(const Toy &toy) {
  this->_name = toy._name;
  this->_picture->data = toy._picture->data;
  this->_error.setWhere(toy._error.getWhere());
  this->_error.setWhat(toy._error.getWhat());
  this->_error.setErrorType(toy._error.getErrorType());
  return *this;
}

bool Toy::speak(const std::string &statement) {
  std::cout << this->getName() << " \"" << statement << "\"" << std::endl;
  return true;
}

Toy &Toy::operator<<(const std::string &string) {
  this->_picture->data = string;
  return *this;
}

bool Toy::speak_es(const std::string &statement) {
  (void)statement;
  this->_error.setWhat("wrong mode");
  this->_error.setWhere("speak_es");
  this->_error.setErrorType(Toy::Error::SPEAK);
  return false;
}

Toy::Error Toy::getLastError() {
  return this->_error;
}

std::ostream &operator<<(std::ostream &stream, const Toy &toy) {
  stream << toy.getName() << std::endl;
  stream << toy.getAscii() << std::endl;
  return stream;
}

std::string Toy::Error::what() {
  return this->_what;
}

std::string Toy::Error::where() {
  return this->_where;
}

void Toy::Error::setWhat(std::string what) {
  this->_what = what;
}

void Toy::Error::setWhere(std::string where) {
  this->_where = where;
}

void Toy::Error::setErrorType(Toy::Error::ErrorType type) {
  this->type = type;
}

std::string Toy::Error::getWhat() const{
  return this->_what;
}

std::string Toy::Error::getWhere() const{
  return this->_where;
}

Toy::Error::ErrorType Toy::Error::getErrorType() const{
  return this->type;
}
