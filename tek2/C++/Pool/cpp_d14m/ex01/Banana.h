/*
** Banana.h for cpp_d14m in /home/gogo/rendu/tek2/cpp_d14m/ex00/Banana.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 17 10:19:56 2017 Gauthier CLER
** Last update Tue Jan 17 10:19:56 2017 Gauthier CLER
*/

#ifndef CPP_D14M_BANANA_H
#define CPP_D14M_BANANA_H


#include "Fruit.h"

class Banana : public Fruit{
public:
  Banana();
  virtual ~Banana();
  virtual std::string	getName() const;
};


#endif //CPP_D14M_BANANA_H
