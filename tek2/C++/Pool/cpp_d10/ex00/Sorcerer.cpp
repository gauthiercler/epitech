/*
** Sorcerer.cpp for cpp_d09 in /home/gogo/rendu/tek2/cpp_d10/ex00/Sorcerer.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 13 10:36:11 2017 Gauthier CLER
// Last update Fri Jan 13 11:34:56 2017 Gauthier Cler
*/


#include "Sorcerer.hh"

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title){
  std::cout << this->getName() << ", " << this->getTitle() << ", is born !" << std::endl;
}

Sorcerer::~Sorcerer(){
  std::cout << this->getName() << ", " << this->getTitle() << ", is dead. Consequences will never be the same !" << std::endl;
}

std::ostream &operator<<(std::ostream &stream, Sorcerer const &sorcerer){
  stream << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and I like ponies !" << std::endl;
  return stream;
} 

std::string	Sorcerer::getName() const{
  return this->_name;
}

std::string	Sorcerer::getTitle() const{
  return this->_title;
}

void		Sorcerer::setName(std::string name) {
  this->_name = name;
}

void		Sorcerer::setTitle(std::string title) {
  this->_title = title;
}

void		Sorcerer::polymorph(const Victim &victim) const{
  victim.getPolymorphed();
}
