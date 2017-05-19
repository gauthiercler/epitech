/*
** FULL_ADDER.hpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/components/FULL_ADDER.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Wed Feb 22 14:41:10 2017 Anas Buyumad
** Last update Wed Feb 22 14:41:10 2017 Anas Buyumad
*/

#ifndef CPP_NANOTEKSPICE_FULL_ADDER_HPP
#define CPP_NANOTEKSPICE_FULL_ADDER_HPP

#include <sources/classes/AComponent.hpp>

class FULL_ADDER : public nts::AComponent{

public:
  FULL_ADDER(const std::string &name = "FULL ADDER");
  virtual ~FULL_ADDER();
};

#endif //CPP_NANOTEKSPICE_FULL_ADDER_HPP
