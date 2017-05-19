/*
** TacticalMarine.hh for cpp_d09 in /home/gogo/rendu/tek2/cpp_d10/ex02/TacticalMarine.hh
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 13 14:36:46 2017 Gauthier CLER
** Last update Fri Jan 13 14:36:46 2017 Gauthier CLER
*/


#ifndef CPP_D09_TACTICALMARINE_HH
#define CPP_D09_TACTICALMARINE_HH


#include "ISpaceMarine.hh"

class TacticalMarine : virtual public ISpaceMarine{
public:
  TacticalMarine();
  virtual ~TacticalMarine();
  virtual TacticalMarine* clone() const;
  virtual void battleCry() const;
  virtual void rangedAttack() const;
  virtual void meleeAttack() const;
};


#endif //CPP_D09_TACTICALMARINE_HH
