/*
** koalanurse.h for cpp_d06 in /home/gogo/rendu/tek2/cpp_d06/ex03/koalanurse.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jan 09 16:10:59 2017 Gauthier CLER
** Last update Mon Jan 09 16:10:59 2017 Gauthier CLER
*/

#ifndef CPP_D06_KOALANURSE_H
#define CPP_D06_KOALANURSE_H

#include <string>
#include "sickkoala.h"

class KoalaNurse
{
private:
  int		ID;
  bool		isWorking;

public:
  KoalaNurse(int ID);
  ~KoalaNurse();
  std::string	readReport(std::string filename);
  void		giveDrug(std::string drug, SickKoala *Koala);
  void		timeCheck();

};

#endif //CPP_D06_KOALANURSE_H
