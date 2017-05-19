/*
** C4081.hpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/components/C4081.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Jan 27 20:42:30 2017 Anas Buyumad
** Last update Fri Jan 27 20:42:30 2017 Anas Buyumad
*/

#ifndef CPP_NANOTEKSPICE_C4081_HPP
#define CPP_NANOTEKSPICE_C4081_HPP

#include <sources/classes/AComponent.hpp>

class C4081 : public nts::AComponent{

public:

  C4081(const std::string &name = "QUAD 2 INPUT AND GATE");
  virtual ~C4081();
};


#endif //CPP_NANOTEKSPICE_C4081_HPP
