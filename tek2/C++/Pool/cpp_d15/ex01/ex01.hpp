/*
** ex01.hpp for cpp_d14m in /home/gogo/rendu/tek2/cpp_d15/ex01/ex01.hpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Jan 18 10:26:27 2017 Gauthier CLER
** Last update Wed Jan 18 10:26:27 2017 Gauthier CLER
*/

#ifndef CPP_D14M_EX01_HPP
#define CPP_D14M_EX01_HPP

#include <cstring>

template <typename T>
int	compare(const T &a, const T &b)
{
  if (a > b)
    return 1;
  if (a < b)
    return -1;
  return 0;
}

template <>
int	compare<const char*>(const char * const &a, const char * const &b)
{
  if (strcmp(a, b) == 0)
    return 0;
  if (std::strcmp(a, b) > 0)
    return 1;
  return -1;
}


#endif //CPP_D14M_EX01_HPP
