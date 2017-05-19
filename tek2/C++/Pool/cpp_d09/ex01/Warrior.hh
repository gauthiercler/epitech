/*
** Warrior.hh for cpp_d09 in /home/gogo/rendu/tek2/cpp_d09/ex01/Warrior.hh
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jan 12 15:01:51 2017 Gauthier CLER
** Last update Thu Jan 12 15:01:51 2017 Gauthier CLER
*/


#ifndef CPP_D09_WARRIOR_HH
#define CPP_D09_WARRIOR_HH


#include "Character.hh"

class Warrior : public Character{

private:
  const std::string	_weapon;
  bool			_isRange;
  bool			getIsRange() const;
  void			setIsRange(bool range);

public:
  Warrior(const std::string &name, int level);
  ~Warrior();
  int	CloseAttack();
  int	RangeAttack();
  const std::string	getWeapon() const;
};


#endif //CPP_D09_WARRIOR_HH
