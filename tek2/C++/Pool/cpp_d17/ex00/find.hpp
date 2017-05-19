/*
** find.hpp for cpp_d16 in /home/gogo/rendu/tek2/cpp_d17/ex00/find.hpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 20 10:17:02 2017 Gauthier CLER
** Last update Fri Jan 20 10:17:02 2017 Gauthier CLER
*/

#ifndef CPP_D16_FIND_HPP
#define CPP_D16_FIND_HPP


#include <algorithm>

template <typename T>
typename T::iterator	do_find(T &tp, int value)
{
  return std::find(tp.begin(), tp.end(), value);
}

#endif //CPP_D16_FIND_HPP
