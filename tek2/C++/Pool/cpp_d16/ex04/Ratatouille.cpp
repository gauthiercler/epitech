/*
** Ratatouille.cpp for cpp_d16 in /home/gogo/rendu/tek2/cpp_d16/ex04/Ratatouille.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jan 19 10:13:46 2017 Gauthier CLER
** Last update Thu Jan 19 10:13:46 2017 Gauthier CLER
*/

#include "Ratatouille.h"

Ratatouille::Ratatouille() : _sentence(std::string()){

}

Ratatouille::~Ratatouille() {

}

Ratatouille::Ratatouille(Ratatouille const &other){
  this->_sentence.str(std::string());
  this->_sentence.clear();
  this->_sentence << other._sentence.rdbuf();
}

Ratatouille &Ratatouille::operator=(const Ratatouille &other) {
  this->_sentence.str(std::string());
  this->_sentence.clear();
  this->_sentence << other._sentence.rdbuf();
  return *this;
}

Ratatouille &Ratatouille::addVegetable(unsigned char vegetable) {
  this->_sentence << vegetable;
  return *this;
}

Ratatouille &Ratatouille::addCondiment(unsigned int condiment) {
  this->_sentence << condiment;
  return *this;
}

Ratatouille &Ratatouille::addSpice(double spice) {
  this->_sentence << spice;
  return *this;
}

Ratatouille &Ratatouille::addSauce(const std::string &sauce) {
  this->_sentence << sauce;
  return *this;
}

std::string Ratatouille::kooc(void) {
  return this->_sentence.str();
}
