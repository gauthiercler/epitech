/*
** Woody.h for cpp_d09 in /home/gogo/rendu/tek2/cpp_d13/ex02/Woody.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jan 16 11:08:07 2017 Gauthier CLER
** Last update Mon Jan 16 11:08:07 2017 Gauthier CLER
*/


#ifndef CPP_D09_WOODY_H
#define CPP_D09_WOODY_H


#include "Toy.h"

class Woody : public Toy {
public:
  Woody(std::string name, std::string ascii = "woody.txt");
  virtual ~Woody();
};


#endif //CPP_D09_WOODY_H
