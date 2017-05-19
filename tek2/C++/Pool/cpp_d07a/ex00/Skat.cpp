/*
** Skat.cpp for cpp_d07m in /home/gogo/rendu/tek2/cpp_d07a/ex00/Skat.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 10 18:12:53 2017 Gauthier CLER
** Last update Tue Jan 10 18:12:53 2017 Gauthier CLER
*/

#include <iostream>
#include "Skat.h"

Skat::Skat(std::string const &name, int stimPaks) {
  this->_name = name;
  this->_stimPaks = stimPaks;
}

Skat::~Skat() {

}

const std::string &Skat::name() {
  return this->_name;
}

void Skat::addStimPaks(unsigned int number) {
  if (number == 0)
    std::cout << "Hey boya, did you forget something ?" << std::endl;
  else
    this->_stimPaks += number;
}

void Skat::useStimPaks() {
  if (this->_stimPaks > 0){
    std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
    this->_stimPaks -= 1;
  }else
    std::cout << "Mediiiiiic" << std::endl;
}

void Skat::status() {
  std::cout << "Soldier " << this->_name << " reporting " << this->_stimPaks << " stimpaks remaining sir !" << std::endl;
}

int & Skat::stimPaks() {
  return this->_stimPaks;
}

void Skat::shareStimPaks(int number, int &stock) {
  if (this->_stimPaks < number){
    std::cout << "Don't be greedy" << std::endl;
  }else{
    std::cout << "Keep the change." << std::endl;
    stock += number;
    this->_stimPaks -= number;
  }
}
