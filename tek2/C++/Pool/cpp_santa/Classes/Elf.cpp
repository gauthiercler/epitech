/*
** Elf.cpp for cpp_santa in /home/ventinc/epitech/piscine/cpp_santa/Classes/Elf.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Sat Jan 14 14:15:27 2017 Vincent DUSAUTOIR
** Last update Sat Jan 14 14:15:27 2017 Vincent DUSAUTOIR
*/

#include <iostream>
#include "Elf.hpp"

Elf::Elf(const std::string &name): _name(name), _leftHand(NULL), _rightHand(NULL){

}

Elf::Elf(const Elf &elf): _name(elf.getName()), _leftHand(elf.getLeftHand()->clone()), _rightHand(elf.getRightHand()->clone()){

}

Elf::~Elf() {
  if (this->getLeftHand() != NULL)
    delete this->getLeftHand();
  if (this->getRightHand() != NULL)
    delete this->getRightHand();
}

bool Elf::take(ITable &table) {
  if (this->getRightHand() == NULL && table.getItemsNumber() != 0) {
    this->setRightHand(table.take());
    this->getRightHand()->isTaken();
    return true;
  } else if (this->getLeftHand() != NULL)
    return true;
  return false;
}

bool Elf::take(IConveyorBelt &conveyorBelt) {
  if (this->getLeftHand() == NULL && conveyorBelt.look() != NULL){
    std::cout << "whistles while working" << std::endl;
    this->setLeftHand(conveyorBelt.take());
    this->getLeftHand()->isTaken();
    return true;
  } else if (this->getLeftHand() != NULL)
    return true;
  return false;
}

bool Elf::put(ITable &table) {
  bool		tablePut;

  if (this->getRightHand() != NULL) {
    if (!(tablePut = table.put(this->getRightHand()))) {
      std::cout << "The elf named " << this->getName() << " throws brutally the object " << this->getRightHand()->getName() << "." << std::endl;
      this->getRightHand()->isPut();
    }
    else
      delete this->getRightHand();
    this->setRightHand(NULL);
    return tablePut;
  }
  return false;
}

bool Elf::put(IConveyorBelt &conveyorBelt) {
  if (this->getLeftHand() != NULL) {
    if (conveyorBelt.put(this->getLeftHand())) {
      this->setLeftHand(NULL);
      return true;
    }
  }
  return false;
}

bool Elf::craftGift(AWrap &wrap, AObject &object) {
  return wrap.wrapMeThat(&object);
}

bool Elf::createGift(IConveyorBelt &conveyorBelt, ITable &table) {
  if (!conveyorBelt.in()) {
    std::cout << "[" << this->getName() << "]: I can't wrap without a box." << std::endl;
    return false;
  }
  if (this->take(conveyorBelt) && this->take(table)) {
    if (this->getLeftHand() != NULL && this->getRightHand() != NULL && this->craftGift(*static_cast<AWrap*>(this->getLeftHand()), *this->getRightHand())) {
      this->setRightHand(this->getLeftHand());
      this->setLeftHand(NULL);
      std::cout << "tuuuut tuuut tuut" << std::endl;
      if (!conveyorBelt.in()) {
	std::cout << "[" << this->getName() << "]: I can't wrap without a wrapper." << std::endl;
	return false;
      }
      if (this->take(conveyorBelt) && this->getLeftHand() != NULL && this->craftGift(*static_cast<AWrap*>(this->getLeftHand()), *this->getRightHand())) {
	std::cout << "tuuuut tuuut tuut" << std::endl;
	this->setRightHand(NULL);
	this->put(conveyorBelt);
	conveyorBelt.out();
	std::cout << "[" << this->getName() << "]: A little children will be very happy ! (＾▽＾)" << std::endl;
	return true;
      }
    }
  }
  std::cout << "["<< this->getName() << "]: I can't wrap without a WRAPPER AND AN OBJECT !  (╯°□°）╯︵ ┻━┻" << std::endl;
  return false;
}

AObject *Elf::getLeftHand() const {
  return this->_leftHand;
}

AObject *Elf::getRightHand() const {
  return this->_rightHand;
}

const std::string &Elf::getName() const {
  return this->_name;
}

void Elf::setLeftHand(AObject *object) {
  this->_leftHand = object;
}

void Elf::setRightHand(AObject *object) {
  this->_rightHand = object;
}

void Elf::setName(const std::string &name) {
  this->_name = name;
}

Elf &Elf::operator=(const Elf &elf) {
  this->setRightHand(elf.getRightHand()->clone());
  this->setLeftHand(elf.getLeftHand()->clone());
  this->setName(elf.getName());
  return *this;
}
