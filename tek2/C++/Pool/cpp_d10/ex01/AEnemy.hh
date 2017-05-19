/*
** AEnemy.hh for cpp_d09 in /home/gogo/rendu/tek2/cpp_d10/ex01/AEnemy.hh
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 13 11:49:02 2017 Gauthier CLER
** Last update Fri Jan 13 11:49:02 2017 Gauthier CLER
*/


#ifndef CPP_D09_AENEMY_HH
#define CPP_D09_AENEMY_HH


#include <string>

class AEnemy {
private:
  int			_hp;
  const std::string	_type;
public:
  AEnemy(int hp, std::string const & type);
  virtual ~AEnemy();
  std::string const getType() const;
  int getHP() const;
  void	setHP(int hp);
  virtual void takeDamage(int damage);
};


#endif //CPP_D09_AENEMY_HH
