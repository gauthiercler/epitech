/*
** DomesticKoala.h for cpp_d16 in /home/gogo/rendu/tek2/cpp_d16/ex01/DomesticKoala.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jan 19 14:43:16 2017 Gauthier CLER
** Last update Thu Jan 19 14:43:16 2017 Gauthier CLER
*/

#ifndef CPP_D16_DOMESTICKOALA_H
#define CPP_D16_DOMESTICKOALA_H


#include <vector>
#include <string>
#include <map>
#include "KoalaAction.h"

class DomesticKoala {
public:
  DomesticKoala(KoalaAction&);
  ~DomesticKoala();
  DomesticKoala(const DomesticKoala&);
  DomesticKoala& operator=(const DomesticKoala&);
  typedef void (KoalaAction::*methodPointer_t)(const std::string &string);
  std::vector<methodPointer_t> const * getActions(void) const;
  void learnAction(unsigned char, methodPointer_t);
  void unlearnAction(unsigned char);
  void doAction(unsigned char, const std::string&);
  void setKoalaAction(KoalaAction&action);
  KoalaAction	getKoala() const;
  void		setKoala(KoalaAction koala);
private:
  std::map<unsigned char, methodPointer_t>	_map;
  KoalaAction					_koala;
};


#endif //CPP_D16_DOMESTICKOALA_H
