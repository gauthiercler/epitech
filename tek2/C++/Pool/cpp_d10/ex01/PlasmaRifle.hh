/*
** PlasmaRifle.hh for cpp_d09 in /home/gogo/rendu/tek2/cpp_d10/ex01/PlasmaRifle.hh
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 13 11:49:24 2017 Gauthier CLER
** Last update Fri Jan 13 11:49:24 2017 Gauthier CLER
*/


#ifndef CPP_D09_PLASMARIFLE_HH
#define CPP_D09_PLASMARIFLE_HH

#include "AWeapon.hh"

class PlasmaRifle : virtual public AWeapon{
public:
  PlasmaRifle();
  virtual ~PlasmaRifle();
  virtual void	attack() const;
};


#endif //CPP_D09_PLASMARIFLE_HH
