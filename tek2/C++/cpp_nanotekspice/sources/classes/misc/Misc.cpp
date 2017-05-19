/*
** Misc.cpp for cpp_nanotekspice in /home/gogo/rendu/tek2/cpp_nanotekspice/sources/classes/misc/Misc.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Feb 15 00:15:05 2017 Gauthier Cler
** Last update Wed Feb 15 00:15:05 2017 Gauthier Cler
*/

#include <iostream>
#include "Misc.hpp"

std::string nts::Misc::trim(std::string &str) {

  if (str.length() == 0)
    return str;
  size_t first = str.find_first_not_of(" \t");
  size_t last = str.find_last_not_of(" \t");

  return str.substr(first, (last - first + 1));
}
