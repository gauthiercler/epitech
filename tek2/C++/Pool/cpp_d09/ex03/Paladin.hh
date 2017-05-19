/*
** Paladin.hh for cpp_d09 in /home/gogo/rendu/tek2/cpp_d09/ex03/Paladin.hh
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jan 12 17:14:47 2017 Gauthier CLER
** Last update Thu Jan 12 17:14:47 2017 Gauthier CLER
*/


#ifndef CPP_D09_PALADIN_HH
#define CPP_D09_PALADIN_HH


#include "Warrior.hh"
#include "Priest.hh"

class Paladin : virtual public Warrior, virtual public Priest{


public:
  Paladin(const std::string &name, int level);
  ~Paladin();
  int	CloseAttack();
  int	RangeAttack();
  void	Heal();
  void	RestorePower();
  int	Intercept();
};


#endif //CPP_D09_PALADIN_HH
