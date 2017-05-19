/*
** sickkoalalist.h for cpp_d06 in /home/gogo/rendu/tek2/cpp_d06/ex05/sickkoalalist.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jan 09 21:47:38 2017 Gauthier CLER
** Last update Mon Jan 09 21:47:38 2017 Gauthier CLER
*/


#ifndef CPP_D06_SICKKOALALIST_H
#define CPP_D06_SICKKOALALIST_H


#include "sickkoala.h"

class SickKoalaList {

private:
  SickKoala	*koala;
  SickKoalaList	*next;
  SickKoalaList	*prev;

public:
  SickKoalaList(SickKoala *Koala);
  ~SickKoalaList();
  bool			isEnd();
  void			append(SickKoalaList *node);
  SickKoala		*getFromName(std::string name);
  SickKoalaList		*remove(SickKoalaList *node);
  SickKoalaList		*removeFromName(std::string name);
  SickKoalaList		*getNext();
  SickKoala		*getContent();
  void			dump();
};


#endif //CPP_D06_SICKKOALALIST_H
