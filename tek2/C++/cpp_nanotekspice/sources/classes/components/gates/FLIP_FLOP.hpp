/*
** FLIP_FLOP.hpp for cpp_nanotekspice in /home/gogo/rendu/tek2/cpp_nanotekspice/sources/classes/components/FLIP_FLOP.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sat Feb 25 19:04:57 2017 Gauthier Cler
** Last update Sat Feb 25 19:04:57 2017 Gauthier Cler
*/

#ifndef CPP_NANOTEKSPICE_FLIP_FLOP_HPP
#define CPP_NANOTEKSPICE_FLIP_FLOP_HPP


#include <sources/classes/AComponent.hpp>

class FLIP_FLOP : public nts::AComponent {
  FLIP_FLOP(const std::string &name = "FLIP_FLOP");
  virtual ~FLIP_FLOP();
  virtual nts::Tristate 	Compute(size_t pin_num_this = 1);
};


#endif //CPP_NANOTEKSPICE_FLIP_FLOP_HPP
