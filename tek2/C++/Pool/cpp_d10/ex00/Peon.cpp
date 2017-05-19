/*
** Sorcerer.cpp for cpp_d09 in /home/gogo/rendu/tek2/cpp_d10/ex00/Sorcerer.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 13 10:36:11 2017 Gauthier CLER
// Last update Fri Jan 13 11:15:17 2017 Gauthier Cler
*/


#include "Peon.hh"

Peon::Peon(std::string name) : Victim(name), _name(name){
  std::cout << "Zog zog."  << std::endl;
}

Peon::~Peon(){
  std::cout << "Bleuark..." << std::endl;
}

std::ostream &operator<<(std::ostream &stream, Peon const &peon){
  stream << "I'm " << peon.getName() <<" and i like otters !" << std::endl;
  return stream;
} 

std::string	Peon::getName() const{
  return this->_name;
}

void		Peon::setName(std::string name) {
  this->_name = name;
}

void		Peon::getPolymorphed() const{
  std::cout << this->getName() << " has been turned into a pink pony !" << std::endl;
}
