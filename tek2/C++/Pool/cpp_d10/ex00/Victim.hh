/*
** Victim.cpp for cpp_d09 in /home/gogo/rendu/tek2/cpp_d10/ex00/Victim.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 13 10:36:26 2017 Gauthier CLER
// Last update Fri Jan 13 11:04:23 2017 Gauthier Cler
*/

#ifndef VICTIM_H_
# define VICTIM_H_

#include	<iostream>

class Victim {
public:
  Victim(std::string name);
  ~Victim();
  std::string	getName() const;
  void		setName(std::string name);
  virtual void getPolymorphed() const;

private:
  std::string	_name;
};

std::ostream &operator<<(std::ostream &stream, Victim const &victim);

#endif
