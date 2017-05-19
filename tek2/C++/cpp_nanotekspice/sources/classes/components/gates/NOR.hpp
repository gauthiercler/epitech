/*
** NOR.hpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/gates/NOR.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Jan 27 20:29:35 2017 Anas Buyumad
** Last update Fri Jan 27 20:29:35 2017 Anas Buyumad
*/

#ifndef CPP_NANOTEKSPICE_NOR_HPP
#define CPP_NANOTEKSPICE_NOR_HPP

#include <sources/classes/AComponent.hpp>

class NOR : public nts::AComponent {

public:

  NOR(const std::string &name = "NOR");
  virtual ~NOR();

  virtual nts::Tristate 	Compute(size_t pin_num_this = 1);
};


#endif //CPP_NANOTEKSPICE_NOR_HPP
