/*
** carrier.hh for cpp_d07m in /home/gogo/rendu/tek2/cpp_d08/ex03/carrier.hh
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Jan 11 18:52:48 2017 Gauthier CLER
** Last update Wed Jan 11 18:52:48 2017 Gauthier CLER
*/


#ifndef CPP_D07M_CARRIER_HH
#define CPP_D07M_CARRIER_HH


#include <string>
#include "droid.hh"

class Carrier {

public:
  Carrier(std::string id = "");
  ~Carrier();
  std::string	getId() const;
  size_t	getSpeed() const;
  size_t	getEnergy() const;
  void		setId(std::string id);
  void		setSpeed(size_t speed);
  void		setEnergy(size_t energy);
  void		displayTeam() const;
  size_t	getNbDroids() const;

  Carrier &operator<<(Droid * &droid);
  Carrier &operator>>(Droid * &droid);
  Droid *& operator[](const size_t &index);
  Droid * const & operator[](const size_t &index) const;
  Carrier &operator~();
  bool	operator()(const int & x, const int  & y);


private:
  std::string	_id;
  size_t	_energy;
  size_t const	_attack;
  size_t const	_toughness;
  size_t	_speed;
  Droid		*_droids[5];
  void		updateSpeed();
};

std::ostream& operator<<(std::ostream &stream, Carrier const &carrier);


#endif //CPP_D07M_CARRIER_HH
