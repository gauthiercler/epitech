/*
** koaladoctorlist.h for cpp_d06 in /home/gogo/rendu/tek2/cpp_d06/ex05/koaladoctorlist.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jan 09 21:46:57 2017 Gauthier CLER
** Last update Mon Jan 09 21:46:57 2017 Gauthier CLER
*/


#ifndef CPP_D06_KOALADOCTORLIST_H
#define CPP_D06_KOALADOCTORLIST_H


#include "koaladoctor.h"

class KoalaDoctorList {

private:
  KoalaDoctor	*koala;
  KoalaDoctorList	*next;
  KoalaDoctorList	*prev;

public:
  KoalaDoctorList(KoalaDoctor *Koala);
  ~KoalaDoctorList();
  bool			isEnd();
  void			append(KoalaDoctorList *node);
  KoalaDoctor		*getFromName(std::string name);
  KoalaDoctorList		*remove(KoalaDoctorList *node);
  KoalaDoctorList		*removeFromName(std::string name);
  KoalaDoctorList		*getNext();
  KoalaDoctor		*getContent();
  void			dump();
};

#endif //CPP_D06_KOALADOCTORLIST_H
