/*
** CLOCK.hpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/components/CLOCK.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Feb 09 22:19:03 2017 Anas Buyumad
** Last update Thu Feb 09 22:19:03 2017 Anas Buyumad
*/

#ifndef CPP_NANOTEKSPICE_CLOCK_HPP
#define CPP_NANOTEKSPICE_CLOCK_HPP

#include <sources/classes/AComponent.hpp>

class CLOCK : public nts::AComponent {
private:
  nts::Tristate		Save;
public:

  CLOCK(const std::string &name = "CLOCK");
  virtual ~CLOCK();
  void	InvertClock();
  nts::Tristate		getSave(void);
};


#endif //CPP_NANOTEKSPICE_CLOCK_HPP
