/*
** droid.hh for cpp_d07m in /home/gogo/rendu/tek2/cpp_d08/ex00/droid.hh
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Jan 11 10:48:06 2017 Gauthier CLER
** Last update Wed Jan 11 10:48:07 2017 Gauthier CLER
*/

#ifndef CPP_D07M_DROID_HH
#define CPP_D07M_DROID_HH


#include <string>

class Droid {
public:
  Droid(std::string serial = "");
  Droid(Droid const & otherDroid);
  ~Droid();
  std::string	getId() const;
  size_t	getEnergy() const;
  size_t	getAttack() const;
  size_t	getToughness() const;
  std::string	*getStatus() const;
  void		setId(std::string const & id);
  void		setEnergy(size_t const & energy);
  void		setStatus(std::string * status);
  bool		operator==(Droid const & otherDroid) const;
  Droid &        operator<<(size_t & stock);
  bool		operator!=(Droid const & otherDroid) const;
  Droid &	operator=(Droid const & otherDroid);
private:
  std::string	_id;
  size_t	_energy;
  const size_t	_attack;
  const size_t 	_toughness;
  std::string	*_status;

};

std::ostream& operator<<(std::ostream &stream, Droid const &droid);

#endif //CPP_D07M_DROID_HH
