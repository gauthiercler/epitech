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
}

Toy::Toy(const Toy &toy): _type(toy.getType()), _name(toy.getName()), _picture(new Picture(*_picture)){
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
  return this->_picture->getPictureFromFile(name);
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
  return *this;
}

void Toy::speak(std::string statement) {
  std::cout << this->getName() << " \"" << statement << "\"" << std::endl;
}

Toy &Toy::operator<<(const std::string &string) {
  this->_picture->data = string;
  return *this;
}

std::ostream &operator<<(std::ostream &stream, const Toy &toy) {
  stream << toy.getName() << std::endl;
  stream << toy.getAscii() << std::endl;
  return stream;
}
