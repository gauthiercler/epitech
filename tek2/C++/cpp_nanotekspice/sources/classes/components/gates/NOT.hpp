/*
** NOT.hpp for cpp_nanotekspice in /home/gogo/rendu/tek2/cpp_nanotekspice/sources/classes/components/gates/NOT.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Feb 17 16:40:20 2017 Gauthier Cler
** Last update Fri Feb 17 16:40:20 2017 Gauthier Cler
*/

#ifndef CPP_NANOTEKSPICE_NOT_HPP
#define CPP_NANOTEKSPICE_NOT_HPP

#include <sources/classes/AComponent.hpp>

class NOT : public nts::AComponent {
public:

  NOT(const std::string &name = "NOT");
  virtual ~NOT();

  virtual nts::Tristate 	Compute(size_t pin_num_this = 1);
};


#endif //CPP_NANOTEKSPICE_NOT_HPP
