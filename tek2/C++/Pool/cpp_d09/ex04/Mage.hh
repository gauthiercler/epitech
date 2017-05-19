/*
** Mage.hh for cpp_d09 in /home/gogo/rendu/tek2/cpp_d09/ex02/Mage.hh
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jan 12 16:16:02 2017 Gauthier CLER
** Last update Thu Jan 12 16:16:02 2017 Gauthier CLER
*/


#ifndef CPP_D09_MAGE_HH
#define CPP_D09_MAGE_HH


#include "Character.hh"

class Mage : virtual public Character{
public:
  Mage(const std::string &name, int level);
  ~Mage();
  int	CloseAttack();
  int	RangeAttack();
  void	RestorePower();
};


#endif //CPP_D09_MAGE_HH
