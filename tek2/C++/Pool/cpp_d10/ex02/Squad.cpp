/*
** Squad.cpp for cpp_d09 in /home/gogo/rendu/tek2/cpp_d10/ex02/Squad.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 13 14:36:32 2017 Gauthier CLER
** Last update Fri Jan 13 14:36:32 2017 Gauthier CLER
*/


#include <clocale>
#include <algorithm>
#include "Squad.hh"

Squad::Squad(Squad const &otherSquad) {
  this->_squad = otherSquad._squad;
}

Squad::Squad() {

}

Squad::~Squad() {
  ISpaceMarine* currentMarine;
  for(std::vector<ISpaceMarine*>::iterator i = this->_squad.begin(); i < this->_squad.end(); i += 1) {
    currentMarine = *i;
    delete currentMarine;
  }
}

int Squad::getCount() const{
  return (int) this->_squad.size();
}

ISpaceMarine *Squad::getUnit(int index) {
  if (this->getCount() < index - 1)
    return NULL;
  return this->_squad.at((unsigned long)index);
}

Squad &Squad::operator=(Squad const &otherSquad) {
  this->_squad.clear();
  this->_squad = otherSquad._squad;
  return *this;
}

int Squad::push(ISpaceMarine *marine) {
  if (marine != NULL){
      if (find(this->_squad.begin(), this->_squad.end(), marine) == this->_squad.end()){
	this->_squad.push_back(marine);
    }
  }
  return this->getCount();
}
