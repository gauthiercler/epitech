/*
** PowerFist.hh for cpp_d09 in /home/gogo/rendu/tek2/cpp_d10/ex01/PowerFist.hh
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 13 11:49:34 2017 Gauthier CLER
** Last update Fri Jan 13 11:49:35 2017 Gauthier CLER
*/


#ifndef CPP_D09_POWERFIST_HH
#define CPP_D09_POWERFIST_HH

#include "AWeapon.hh"

class PowerFist : virtual public AWeapon{
public:
  PowerFist();
  virtual ~PowerFist();
  virtual void	attack() const;
};


#endif //CPP_D09_POWERFIST_HH
