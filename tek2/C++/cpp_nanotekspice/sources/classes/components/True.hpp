/*
** TRUE.hpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/components/TRUE.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Feb 05 20:08:40 2017 Anas Buyumad
** Last update Sun Feb 05 20:08:40 2017 Anas Buyumad
*/

#ifndef CPP_NANOTEKSPICE_TRUE_HPP
#define CPP_NANOTEKSPICE_TRUE_HPP

#include <sources/classes/AComponent.hpp>

class True : public nts::AComponent {

public:

  True(const std::string &name = "TRUE");
  virtual ~True();
};


#endif //CPP_NANOTEKSPICE_TRUE_HPP
