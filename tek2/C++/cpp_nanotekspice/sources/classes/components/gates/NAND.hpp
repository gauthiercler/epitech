/*
** NAND.hpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/gates/NAND.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Jan 27 20:27:16 2017 Anas Buyumad
** Last update Fri Jan 27 20:27:16 2017 Anas Buyumad
*/

#ifndef CPP_NANOTEKSPICE_NAND_HPP
#define CPP_NANOTEKSPICE_NAND_HPP

#include <sources/classes/AComponent.hpp>

class NAND : public nts::AComponent {

public:

  NAND(const std::string &name = "NAND");
  virtual ~NAND();

  virtual nts::Tristate 	Compute(size_t pin_num_this = 1);
};


#endif //CPP_NANOTEKSPICE_NAND_HPP
