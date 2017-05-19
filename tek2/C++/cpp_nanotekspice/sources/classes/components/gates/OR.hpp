/*
** OR.hpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/gates/OR.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Jan 27 20:28:28 2017 Anas Buyumad
** Last update Fri Jan 27 20:28:28 2017 Anas Buyumad
*/

#ifndef CPP_NANOTEKSPICE_OR_HPP
#define CPP_NANOTEKSPICE_OR_HPP

#include <sources/classes/AComponent.hpp>

class OR : public nts::AComponent {

public:

  OR(const std::string &name = "OR");
  ~OR();

  virtual nts::Tristate 	Compute(size_t pin_num_this = 1);
};


#endif //CPP_NANOTEKSPICE_OR_HPP
