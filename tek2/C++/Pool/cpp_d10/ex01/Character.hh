/*
** Character.hh for cpp_d09 in /home/gogo/rendu/tek2/cpp_d10/ex01/Character.hh
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 13 11:48:55 2017 Gauthier CLER
** Last update Fri Jan 13 11:48:55 2017 Gauthier CLER
*/


#ifndef CPP_D09_CHARACTER_HH
#define CPP_D09_CHARACTER_HH


#include <string>
#include "AWeapon.hh"
#include "AEnemy.hh"

class Character {
private:
  const std::string	_name;
  int			_actionPoints;
  AWeapon		*_weapon;
public:
  Character(std::string const & name);
  ~Character();
  void recoverAP();
  void equip(AWeapon* weapon);
  void attack(AEnemy* enemy);
  std::string const getName() const;
  int	getActionPoints() const;
  void	setActionPoints(int actionPoints);
  AWeapon	*getWeapon() const;

};

std::ostream & operator<<(std::ostream & stream, Character const &character);

#endif //CPP_D09_CHARACTER_HH
