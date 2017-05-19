/*
** C4071.hpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/components/C4071.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Jan 27 20:42:08 2017 Anas Buyumad
** Last update Fri Jan 27 20:42:08 2017 Anas Buyumad
*/

#ifndef CPP_NANOTEKSPICE_C4071_HPP
#define CPP_NANOTEKSPICE_C4071_HPP

#include <sources/classes/AComponent.hpp>

class C4071 : public nts::AComponent{

public:

  C4071(const std::string &name = "QUAD 2 INPUT OR GATE");
  virtual ~C4071();
};


#endif //CPP_NANOTEKSPICE_C4071_HPP
