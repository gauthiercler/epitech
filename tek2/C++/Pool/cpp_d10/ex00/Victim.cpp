/*
** Sorcerer.cpp for cpp_d09 in /home/gogo/rendu/tek2/cpp_d10/ex00/Sorcerer.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 13 10:36:11 2017 Gauthier CLER
// Last update Fri Jan 13 11:05:07 2017 Gauthier Cler
*/


#include "Victim.hh"

Victim::Victim(std::string name) : _name(name){
  std::cout << "Some random victim called " << this->getName() << " just popped !"  << std::endl;
}

Victim::~Victim(){
  std::cout << "Victim " << this->getName() << " just died for no apparent reason !" << std::endl;
}

std::ostream &operator<<(std::ostream &stream, const Victim &victim){
  stream << "I'm " << victim.getName() <<" and i like otters !" << std::endl;
  return stream;
} 

std::string	Victim::getName() const{
  return this->_name;
}

void		Victim::setName(std::string name) {
  this->_name = name;
}

void		Victim::getPolymorphed() const{
  std::cout << this->getName() << " has been turned into a cute little sheep !" << std::endl;
}
