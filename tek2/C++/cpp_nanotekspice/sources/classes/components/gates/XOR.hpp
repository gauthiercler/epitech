/*
** XOR.hpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/gates/XOR.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Jan 27 20:30:41 2017 Anas Buyumad
** Last update Fri Jan 27 20:30:41 2017 Anas Buyumad
*/

#ifndef CPP_NANOTEKSPICE_XOR_HPP
#define CPP_NANOTEKSPICE_XOR_HPP

#include <sources/classes/AComponent.hpp>

class XOR : public nts::AComponent {

public:

  XOR(const std::string &name = "XOR");
  virtual ~XOR();

  virtual nts::Tristate 	Compute(size_t pin_num_this = 1);
};


#endif //CPP_NANOTEKSPICE_XOR_HPP
