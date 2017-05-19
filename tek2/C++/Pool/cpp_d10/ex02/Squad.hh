/*
** Squad.hh for cpp_d09 in /home/gogo/rendu/tek2/cpp_d10/ex02/Squad.hh
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 13 14:36:37 2017 Gauthier CLER
** Last update Fri Jan 13 14:36:37 2017 Gauthier CLER
*/


#ifndef CPP_D09_SQUAD_HH
#define CPP_D09_SQUAD_HH


#include <vector>
#include "ISquad.hh"

class Squad : public ISquad{
private:
  std::vector<ISpaceMarine*> _squad;

public:
  Squad();
  Squad(Squad const &otherSquad);
  virtual ~Squad();
  virtual int	getCount() const;
  virtual ISpaceMarine	*getUnit(int index);
  virtual int		push(ISpaceMarine *marine);


  Squad &operator=(Squad const &otherSquad);
};


#endif //CPP_D09_SQUAD_HH
