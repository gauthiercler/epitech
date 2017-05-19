/*
** Character.hh for cpp_d09 in /home/gogo/rendu/tek2/cpp_d09/ex00/Character.hh
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jan 12 12:09:30 2017 Gauthier CLER
** Last update Thu Jan 12 12:09:30 2017 Gauthier CLER
*/

#ifndef CPP_D09_CHARACTER_HH
#define CPP_D09_CHARACTER_HH


#include <string>


class Character {
private:
  std::string		_name;
  int			_level;
  int			_pv;
  int			_power;
  int			_strength;
  int			_stamina;
  int			_intelligence;
  int			_spirit;
  int			_agility;



protected:
  void		setStrength(const int &strength);
  void		setStamina(const int &stamina);
  void		setIntelligence(const int &intelligence);
  void		setSpirit(const int &spirit);
  void		setAgility(const int &agility);

public:


  Character(const std::string &name, int level);
  Character(Character const &other);
  Character &operator=(Character const &other);
  ~Character();
  enum			AttackRange{
    CLOSE,
    RANGE
  };
  AttackRange		Range;
  const std::string &getName() const;
  int		getLvl() const;
  int		getPv() const;
  int		getPower() const;
  int		getStrength() const;
  int		getStamina() const;
  int		getIntelligence() const;
  int		getSpirit() const;
  int		getAgility() const;
  AttackRange 	getRange() const;
  void		setLvl(const int &lvl);
  void		setPv(const int &pv);
  void		setPower(const int &power);
  void		setName(const std::string &name);
  void		setRange(AttackRange const &range);
  int		CloseAttack();
  int		RangeAttack();
  void		Heal();
  void		RestorePower();
  void		TakeDamage(const int &_damage);

};


#endif //CPP_D09_CHARACTER_HH
