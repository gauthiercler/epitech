/*
** AWeapon.hh for cpp_d09 in /home/gogo/rendu/tek2/cpp_d10/ex01/AWeapon.hh
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 13 11:49:10 2017 Gauthier CLER
** Last update Fri Jan 13 11:49:10 2017 Gauthier CLER
*/


#ifndef CPP_D09_AWEAPON_HH
#define CPP_D09_AWEAPON_HH

#include <string>

class AWeapon {
private:
  const std::string	_name;
  int			_apCost;
  int			_damage;

public:
  AWeapon(std::string const & name, int apCost, int damage);
  virtual ~AWeapon();
  std::string const getName() const;
  int getAPCost() const;
  int getDamage() const;
  void	setAPCost(int apCost);
  void	setDamage(int damage);
  virtual void attack() const = 0;
};

#endif //CPP_D09_AWEAPON_HH
