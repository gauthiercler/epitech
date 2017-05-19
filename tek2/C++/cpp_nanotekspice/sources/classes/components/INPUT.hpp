/*
** INPUT.hpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/components/INPUT.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon Feb 06 22:07:36 2017 Anas Buyumad
** Last update Mon Feb 06 22:07:36 2017 Anas Buyumad
*/

#ifndef CPP_NANOTEKSPICE_INPUT_HPP
#define CPP_NANOTEKSPICE_INPUT_HPP

#include <sources/classes/AComponent.hpp>

class INPUT : public nts::AComponent {

public:

  INPUT(const std::string &name = "INPUT");
  virtual ~INPUT();
};


#endif //CPP_NANOTEKSPICE_INPUT_HPP
