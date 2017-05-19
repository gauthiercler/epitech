/*
** DomesticKoala.cpp for cpp_d16 in /home/gogo/rendu/tek2/cpp_d16/ex01/DomesticKoala.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jan 19 14:43:19 2017 Gauthier CLER
** Last update Thu Jan 19 14:43:19 2017 Gauthier CLER
*/

#include <iostream>
#include "DomesticKoala.h"

DomesticKoala::DomesticKoala(KoalaAction &koala) : _koala(koala){

}

DomesticKoala::~DomesticKoala() {

}

DomesticKoala::DomesticKoala(const DomesticKoala &koala) {
  this->setKoala(koala.getKoala());
  this->_map = std::map<unsigned char, methodPointer_t >(koala._map.begin(), koala._map.end());
}

KoalaAction DomesticKoala::getKoala() const{
  return this->_koala;
}

void DomesticKoala::setKoala(KoalaAction koala) {
  this->_koala = koala;
}

DomesticKoala &DomesticKoala::operator=(const DomesticKoala &koala) {
  this->setKoala(koala.getKoala());
  this->_map = std::map<unsigned char, methodPointer_t >(koala._map.begin(), koala._map.end());
  return *this;
}

void DomesticKoala::learnAction(unsigned char key, DomesticKoala::methodPointer_t method) {
  this->_map[key] = method;
}

void DomesticKoala::doAction(unsigned char key, const std::string &message) {
  if (this->_map[key]){
    (this->_koala.*(this->_map[key]))(message);
  }
}

void DomesticKoala::unlearnAction(unsigned char key) {
  if (this->_map[key])
    this->_map[key] = NULL;
}

void DomesticKoala::setKoalaAction(KoalaAction &action) {
  this->setKoala(action);
  this->_map.clear();
}

const std::vector<DomesticKoala::methodPointer_t> *DomesticKoala::getActions(void) const {
  std::vector<methodPointer_t> *vector = new std::vector<methodPointer_t >;

  for (std::map<unsigned char, methodPointer_t >::const_iterator it = this->_map.begin(); it != this->_map.end(); ++it)
    vector->push_back(it->second);
  return vector;
}
