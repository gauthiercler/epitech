/*
** Woody.cpp for cpp_d09 in /home/gogo/rendu/tek2/cpp_d13/ex02/Woody.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jan 16 11:08:12 2017 Gauthier CLER
** Last update Mon Jan 16 11:08:12 2017 Gauthier CLER
*/


#include <iostream>
#include "Woody.h"

Woody::Woody(std::string name, std::string ascii) : Toy(WOODY, name, ascii){

}

Woody::~Woody() {

}

bool Woody::speak(std::string statement) {
  std::cout << "WOODY: ";
  return Toy::speak(statement);
}
