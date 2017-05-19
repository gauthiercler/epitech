/*
** C4001.hpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/components/C4001.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Jan 27 20:36:00 2017 Anas Buyumad
** Last update Fri Jan 27 20:36:02 2017 Anas Buyumad
*/

#ifndef CPP_NANOTEKSPICE_C4001_HPP
#define CPP_NANOTEKSPICE_C4001_HPP

#include <sources/classes/AComponent.hpp>

class C4001 : public nts::AComponent{

public:

  C4001(const std::string &name = "QUAD 2 INPUT NOR GATE");
  virtual ~C4001();
};


#endif //CPP_NANOTEKSPICE_C4001_HPP
