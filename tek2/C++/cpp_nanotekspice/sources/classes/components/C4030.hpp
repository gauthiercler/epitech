/*
** C4030.hpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/components/C4030.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Jan 27 20:40:09 2017 Anas Buyumad
** Last update Fri Jan 27 20:40:09 2017 Anas Buyumad
*/

#ifndef CPP_NANOTEKSPICE_C4030_HPP
#define CPP_NANOTEKSPICE_C4030_HPP

#include <sources/classes/AComponent.hpp>

class C4030 : public nts::AComponent {

public:

  C4030(const std::string &name = "QUAD 2 INPUT XOR GATE");
  virtual ~C4030();
};


#endif //CPP_NANOTEKSPICE_C4030_HPP
