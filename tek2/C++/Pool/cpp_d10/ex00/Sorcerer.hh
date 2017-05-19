/*
** Sorcerer.hh for cpp_d09 in /home/gogo/rendu/tek2/cpp_d10/ex00/Sorcerer.hh
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 13 10:36:19 2017 Gauthier CLER
// Last update Fri Jan 13 11:31:07 2017 Gauthier Cler
*/


#ifndef CPP_D10_SORCERER_HH
#define CPP_D10_SORCERER_HH

#include	"Victim.hh"

class Sorcerer {
public:
  Sorcerer(std::string name, std::string title);
  ~Sorcerer();
  std::string	getName() const;
  std::string	getTitle() const;
  void		setName(std::string name);
  void		setTitle(std::string title);
  void		polymorph(const Victim &victim) const;

private:
  std::string	_name;
  std::string	_title;
};


std::ostream & operator<<(std::ostream & stream, Sorcerer const &sorcerer);

#endif //CPP_D10_SORCERER_HH
