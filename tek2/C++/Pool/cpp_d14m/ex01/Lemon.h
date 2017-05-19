/*
** Lemon.h for cpp_d14m in /home/gogo/rendu/tek2/cpp_d14m/ex00/Lemon.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 17 10:20:17 2017 Gauthier CLER
** Last update Tue Jan 17 10:20:17 2017 Gauthier CLER
*/

#ifndef CPP_D14M_LEMON_H
#define CPP_D14M_LEMON_H


#include "Fruit.h"

class Lemon : public Fruit{
public:
  Lemon();
  virtual ~Lemon();
  virtual std::string	getName() const;
};


#endif //CPP_D14M_LEMON_H
