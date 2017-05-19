/*
** koaladoctor.h for cpp_d06 in /home/gogo/rendu/tek2/cpp_d06/ex04/koaladoctor.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jan 09 18:32:15 2017 Gauthier CLER
** Last update Mon Jan 09 18:32:15 2017 Gauthier CLER
*/


#ifndef CPP_D06_KOALADOCTOR_H
#define CPP_D06_KOALADOCTOR_H


#include "sickkoala.h"

class KoalaDoctor {

private:
  std::string	name;
  bool		isWorking;

public:
  KoalaDoctor(std::string name);
  ~KoalaDoctor();
  void	diagnose(SickKoala *Koala);
  void	timeCheck();
  std::string	getName();
};


#endif //CPP_D06_KOALADOCTOR_H
