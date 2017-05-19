/*
** carrier.cpp for cpp_d07m in /home/gogo/rendu/tek2/cpp_d08/ex03/carrier.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Jan 11 18:52:53 2017 Gauthier CLER
** Last update Wed Jan 11 18:52:53 2017 Gauthier CLER
*/


#include <iostream>
#include <cstdlib>
#include "carrier.hh"

Carrier::Carrier(std::string id): _energy(300), _attack(100), _toughness(50), _speed(0) {
  this->_id = id;
  for (size_t i = 0; i < 5; i++)
    this->_droids[i] = NULL;
}

Carrier::~Carrier() {
  for (size_t i = 0; i < 5; i++) {
    if (this->_droids[i]){
      delete this->_droids[i];
    }
  }
}

std::string Carrier::getId() const {
  return this->_id;
}

size_t Carrier::getSpeed() const {
  return this->_speed;
}

size_t Carrier::getEnergy() const {
  return this->_energy;
}

void Carrier::setId(std::string id) {
  this->_id = id;
}

void Carrier::setSpeed(size_t speed) {
  this->_speed = speed;
}

void Carrier::setEnergy(size_t energy) {
  this->_energy = energy;
}

Carrier &Carrier::operator<<(Droid * & droid) {

  for (size_t i = 0; i < 5; i++)
  {
    if (this->_droids[i] == NULL){
      this->_droids[i] = droid;
      droid = NULL;
      this->updateSpeed();
      return *this;
    }
  }
  return *this;
}

Carrier &Carrier::operator>>(Droid * & droid) {
  (void)droid;
  for (size_t i = 0; i < 5; i++)
  {
    if (this->_droids[i] != NULL){
      droid = this->_droids[i];
      this->_droids[i] = NULL;
      this->updateSpeed();
      return *this;
    }
  }
  return *this;
}

Droid *& Carrier::operator[](const size_t &index) {
  return this->_droids[index];
}

void Carrier::updateSpeed()  {
  size_t	counter = 0;

  for (size_t i = 0; i < 5; i++)
    if (this->_droids[i] != NULL)
      counter += 1;
  if (counter > 0)
    this->_speed = 100 - (counter * 10);
  else
    this->_speed = 0;
}

Carrier &Carrier::operator~() {
  this->updateSpeed();
  return *this;
}

void Carrier::displayTeam() const{
  std::cout << "Carrier '" << this->getId() << "' Droid(s) on-board:" << std::endl;
  for (size_t i = 0; i < 5; i++)
  {
    std::cout << "[" << i << "] : ";
    if (this->_droids[i] == NULL)
      std::cout << "Free";
    else
     std::cout << *this->_droids[i];
    std::cout << std::endl;
  }
  std::cout << "Speed : " << this->getSpeed() << ", Energy " << this->getEnergy();
}

bool Carrier::operator()(const int & x, const int & y) {
  size_t	cost;
  if (this->_speed == 0)
    return false;
  cost = (std::abs(x) + std::abs(y)) * (10 + this->getNbDroids());
  if (this->_energy < cost)
    return false;
  this->_energy -= cost;
  return true;
}

size_t Carrier::getNbDroids() const {
  size_t	counter = 0;
  for (size_t i = 0; i < 5; i++){
    if (this->_droids[i])
      counter += 1;
  }
  return counter;
}

Droid* const &Carrier::operator[](const size_t &index) const {
  return this->_droids[index];
}

std::ostream &operator<<(std::ostream &stream, Carrier const & carrier) {
  carrier.displayTeam();
  return stream;
}