/*
** C4008.hpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/components/C4008.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Jan 27 20:37:20 2017 Anas Buyumad
** Last update Fri Jan 27 20:37:20 2017 Anas Buyumad
*/

#ifndef CPP_NANOTEKSPICE_C4008_HPP
#define CPP_NANOTEKSPICE_C4008_HPP

#include <sources/classes/AComponent.hpp>

class C4008 : public nts::AComponent{

public:

  C4008(const std::string &name = "FOUR BIT FULL ADDER");
  virtual ~C4008();
};


#endif //CPP_NANOTEKSPICE_C4008_HPP
