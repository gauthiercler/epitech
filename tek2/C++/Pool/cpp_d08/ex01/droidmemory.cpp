/*
** droidmemory.cpp for cpp_d07m in /home/gogo/rendu/tek2/cpp_d08/ex01/droidmemory.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Jan 11 14:38:01 2017 Gauthier CLER
** Last update Wed Jan 11 14:38:01 2017 Gauthier CLER
*/


#include <cstdlib>
#include "droidmemory.hh"

void DroidMemory::setFingerPrint(size_t fingerPring) {
  this->_fingerPrint = fingerPring;
}

void DroidMemory::setExp(size_t exp) {
  this->_exp = exp;
}

DroidMemory::DroidMemory() {
  this->_exp = 0;
  this->_fingerPrint = (size_t)random();
}

DroidMemory::~DroidMemory() {

}

size_t DroidMemory::getFingerPrint() const {
  return this->_fingerPrint;
}

size_t DroidMemory::getExp() const {
  return this->_exp;
}

DroidMemory &DroidMemory::operator<<(DroidMemory const &memory) {

  this->_exp += memory._exp;
  this->_fingerPrint = (memory._fingerPrint ^ this->_fingerPrint);
  return *this;
}

DroidMemory &DroidMemory::operator>>(DroidMemory &memory) {

  memory._exp += this->_exp;
  memory._fingerPrint = (this->_fingerPrint ^ memory._fingerPrint);
  return *this;
}

DroidMemory &DroidMemory::operator+=(DroidMemory const &memory) {
  return DroidMemory::operator<<(memory);
}

DroidMemory &DroidMemory::operator+=(size_t exp) {
  this->_exp += exp;
  this->_fingerPrint = (exp ^ this->_fingerPrint);
  return *this;
}

DroidMemory &DroidMemory::operator+(DroidMemory const &memory) {
  DroidMemory	*newMemory = new DroidMemory;
  newMemory->_exp = this->_exp + memory._exp;
  newMemory->_fingerPrint = (memory._fingerPrint ^ this->_fingerPrint);
  return *newMemory;
}

DroidMemory &DroidMemory::operator+(size_t exp) {
  DroidMemory	*newMemory = new DroidMemory;
  newMemory->_exp = this->_exp + exp;
  newMemory->_fingerPrint = (exp ^ this->_fingerPrint);
  return *newMemory;
}

DroidMemory &DroidMemory::operator=(DroidMemory const & memory) {
  this->_fingerPrint = memory._fingerPrint;
  this->_exp = memory._exp;
  return *this;
}

DroidMemory::DroidMemory(DroidMemory const & memory) {
  this->_exp = memory._exp;
  this->_fingerPrint = memory._fingerPrint;
}

std::ostream &operator<<(std::ostream &stream, DroidMemory const & memory) {
  stream << "DroidMemory '" << memory.getFingerPrint() << "', " << memory.getExp();
  return stream;
}
