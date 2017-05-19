/*
** AND.hpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/gates/AND.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Jan 27 20:23:49 2017 Anas Buyumad
** Last update Fri Jan 27 20:23:49 2017 Anas Buyumad
*/

#ifndef CPP_NANOTEKSPICE_AND_HPP
#define CPP_NANOTEKSPICE_AND_HPP

#include <sources/classes/AComponent.hpp>

class AND : public nts::AComponent {

public:

  AND(const std::string &name = "AND");
  virtual ~AND();

  virtual nts::Tristate 	Compute(size_t pin_num_this = 1);
};


#endif //CPP_NANOTEKSPICE_AND_HPP