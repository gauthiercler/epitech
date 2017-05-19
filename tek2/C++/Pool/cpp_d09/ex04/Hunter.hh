/*
** Hunter.hh for cpp_d09 in /home/gogo/rendu/tek2/cpp_d09/ex04/Hunter.hh
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jan 12 18:41:12 2017 Gauthier CLER
** Last update Thu Jan 12 18:41:12 2017 Gauthier CLER
*/


#ifndef CPP_D09_HUNTER_HH
#define CPP_D09_HUNTER_HH


#include "Character.hh"

class Hunter: virtual public Character {


public:
  Hunter(const std::string &name, int level);
  ~Hunter();
  int	CloseAttack();
  int	RangeAttack();
  void	RestorePower();
  const std::string	getWeapon() const;

protected:
  const std::string	_weapon;
};


#endif //CPP_D09_HUNTER_HH
