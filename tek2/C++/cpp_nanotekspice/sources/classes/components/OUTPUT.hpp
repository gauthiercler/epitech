/*
** OUTPUT.hpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/components/OUTPUT.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Tue Feb 07 17:39:23 2017 Anas Buyumad
** Last update Tue Feb 07 17:39:23 2017 Anas Buyumad
*/

#ifndef CPP_NANOTEKSPICE_OUTPUT_HPP
#define CPP_NANOTEKSPICE_OUTPUT_HPP

#include <sources/classes/AComponent.hpp>

class OUTPUT : public nts::AComponent {

public:

  OUTPUT(const std::string &name = "OUTPUT");
  virtual ~OUTPUT();
};


#endif //CPP_NANOTEKSPICE_OUTPUT_HPP
