/*
** C4013.hpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/components/C4013.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Jan 27 20:38:14 2017 Anas Buyumad
** Last update Fri Jan 27 20:38:14 2017 Anas Buyumad
*/

#ifndef CPP_NANOTEKSPICE_C4013_HPP
#define CPP_NANOTEKSPICE_C4013_HPP

#include <sources/classes/AComponent.hpp>

class C4013 : public nts::AComponent{

public:

  C4013(const std::string &name = "Dual D-Type Flip-Flop");
  virtual ~C4013();
};


#endif //CPP_NANOTEKSPICE_C4013_HPP
