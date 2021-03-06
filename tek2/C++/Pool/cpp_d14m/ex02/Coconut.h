/*
** Coconut.h for cpp_d14m in /home/gogo/rendu/tek2/cpp_d14m/ex02/Coconut.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 17 12:39:30 2017 Gauthier CLER
** Last update Tue Jan 17 12:39:30 2017 Gauthier CLER
*/

#ifndef CPP_D14M_COCONUT_H
#define CPP_D14M_COCONUT_H


#include "Fruit.h"

class Coconut : public Fruit {
public:
  Coconut();
  virtual ~Coconut();
  virtual std::string	getName() const;
};


#endif //CPP_D14M_COCONUT_H
