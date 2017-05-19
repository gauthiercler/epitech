/*
** False.hpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/components/False.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon Feb 06 21:33:54 2017 Anas Buyumad
** Last update Mon Feb 06 21:33:54 2017 Anas Buyumad
*/

#ifndef CPP_NANOTEKSPICE_FALSE_HPP
#define CPP_NANOTEKSPICE_FALSE_HPP


#include <sources/classes/AComponent.hpp>

class False : public nts::AComponent {

public:

  False(const std::string &name = "FALSE");
  virtual ~False();
};


#endif //CPP_NANOTEKSPICE_FALSE_HPP
