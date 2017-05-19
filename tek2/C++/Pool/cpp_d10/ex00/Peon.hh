/*
** Victim.cpp for cpp_d09 in /home/gogo/rendu/tek2/cpp_d10/ex00/Victim.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 13 10:36:26 2017 Gauthier CLER
// Last update Fri Jan 13 11:11:26 2017 Gauthier Cler
*/

#ifndef PEON_H_
# define PEON_H_

#include	"Victim.hh"

class Peon : public Victim {
public:
  Peon(std::string name);
  ~Peon();
  std::string	getName() const;
  void		setName(std::string name);
  virtual void getPolymorphed() const;

private:
  std::string	_name;
};

#endif
