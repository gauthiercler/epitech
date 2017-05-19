/*
** Priest.hh for cpp_d09 in /home/gogo/rendu/tek2/cpp_d09/ex02/Priest.hh
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jan 12 16:16:02 2017 Gauthier CLER
** Last update Thu Jan 12 16:16:02 2017 Gauthier CLER
*/


#ifndef CPP_D09_PRIEST_HH
#define CPP_D09_PRIEST_HH


#include "Character.hh"
#include "Mage.hh"

class Priest : public Mage{
public:
  Priest(const std::string &name, int level);
  ~Priest();
  int	CloseAttack();
  int	RangeAttack();
  void	RestorePower();
  void	Heal();
};


#endif //CPP_D09_PRIEST_HH
