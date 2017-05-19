/*
** C4011.hpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/components/C4011.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Jan 27 20:37:47 2017 Anas Buyumad
** Last update Fri Jan 27 20:37:47 2017 Anas Buyumad
*/

#ifndef CPP_NANOTEKSPICE_C4011_HPP
#define CPP_NANOTEKSPICE_C4011_HPP

#include <sources/classes/AComponent.hpp>

class C4011 : public nts::AComponent{

public:

  C4011(const std::string &name = "QUAD 2 INPUT NAND GATE");
  virtual ~C4011();
};


#endif //CPP_NANOTEKSPICE_C4011_HPP
