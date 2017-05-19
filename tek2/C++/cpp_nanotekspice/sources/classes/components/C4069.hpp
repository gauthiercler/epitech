/*
** C4069.hpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/components/C4069.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Jan 27 20:41:22 2017 Anas Buyumad
** Last update Fri Jan 27 20:41:22 2017 Anas Buyumad
*/

#ifndef CPP_NANOTEKSPICE_C4069_HPP
#define CPP_NANOTEKSPICE_C4069_HPP

#include <sources/classes/AComponent.hpp>

class C4069 : public nts::AComponent{

public:
  C4069(const std::string &name = "SIX NOT GATE");
  virtual ~C4069();
};


#endif //CPP_NANOTEKSPICE_C4069_HPP
