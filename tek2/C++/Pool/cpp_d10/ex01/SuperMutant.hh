/*
** SuperMutant.hh for cpp_d09 in /home/gogo/rendu/tek2/cpp_d10/ex01/SuperMutant.hh
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 13 11:49:57 2017 Gauthier CLER
** Last update Fri Jan 13 11:49:57 2017 Gauthier CLER
*/


#ifndef CPP_D09_SUPERMUTANT_HH
#define CPP_D09_SUPERMUTANT_HH


#include "AEnemy.hh"

class SuperMutant : virtual public AEnemy {

public:
  SuperMutant();
  virtual ~SuperMutant();
  virtual void takeDamage(int damage);
};


#endif //CPP_D09_SUPERMUTANT_HH
