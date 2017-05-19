/*
** Lime.h for cpp_d14m in /home/gogo/rendu/tek2/cpp_d14m/ex01/Lime.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 17 12:04:41 2017 Gauthier CLER
** Last update Tue Jan 17 12:04:43 2017 Gauthier CLER
*/

#ifndef CPP_D14M_LIME_H
#define CPP_D14M_LIME_H


#include <string>
#include "Fruit.h"

class Lime : public Fruit{
public:
  Lime();
  virtual ~Lime();
  virtual std::string	getName() const;
};


#endif //CPP_D14M_LIME_H
