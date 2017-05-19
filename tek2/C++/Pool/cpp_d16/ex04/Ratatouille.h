/*
** Ratatouille.hpp for cpp_d16 in /home/gogo/rendu/tek2/cpp_d16/ex04/Ratatouille.hpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jan 19 10:13:36 2017 Gauthier CLER
** Last update Thu Jan 19 10:13:36 2017 Gauthier CLER
*/

#ifndef CPP_D16_RATATOUILLE_HPP
#define CPP_D16_RATATOUILLE_HPP


#include <sstream>

class Ratatouille {
public:
  Ratatouille();
  Ratatouille(Ratatouille const &);
  Ratatouille &operator=(const Ratatouille &);
  ~Ratatouille();
  Ratatouille &addVegetable(unsigned char);
  Ratatouille &addCondiment(unsigned int);
  Ratatouille &addSpice(double);
  Ratatouille &addSauce(const std::string &);
  std::string		kooc(void);
private:
  std::stringstream	_sentence;
};


#endif //CPP_D16_RATATOUILLE_HPP
