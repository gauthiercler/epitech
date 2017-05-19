/*
** koalanurselist.h for cpp_d06 in /home/gogo/rendu/tek2/cpp_d06/ex05/koalanurselist.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jan 09 21:47:13 2017 Gauthier CLER
** Last update Mon Jan 09 21:47:16 2017 Gauthier CLER
*/


#ifndef CPP_D06_KOALANURSELIST_H
#define CPP_D06_KOALANURSELIST_H


#include "koalanurse.h"

class KoalaNurseList {

private:
  KoalaNurse	*koala;
  KoalaNurseList	*next;
  KoalaNurseList	*prev;

public:
  KoalaNurseList(KoalaNurse *Koala);
  ~KoalaNurseList();
  bool			isEnd();
  void			append(KoalaNurseList *node);
  KoalaNurse		*getFromID(int id);
  KoalaNurseList		*remove(KoalaNurseList *node);
  KoalaNurseList		*removeFromID(int id);
  KoalaNurseList		*getNext();
  KoalaNurse		*getContent();
  void			dump();
};

#endif //CPP_D06_KOALANURSELIST_H
