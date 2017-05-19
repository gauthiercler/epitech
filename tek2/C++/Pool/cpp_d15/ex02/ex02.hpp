/*
** ex02.hpp for cpp_d14m in /home/gogo/rendu/tek2/cpp_d15/ex02/ex02.hpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Jan 18 10:42:04 2017 Gauthier CLER
** Last update Wed Jan 18 10:42:04 2017 Gauthier CLER
*/

#ifndef CPP_D14M_EX02_HPP
#define CPP_D14M_EX02_HPP

#include <iostream>

template<typename T>
T	min(const T &a, const T &b)
{
  std::cout << "template min" << std::endl;
  if (b < a)
    return b;
  return a;
}

int	min(const int &a, const int &b)
{
  std::cout << "non-template min" << std::endl;
  if (b < a)
    return b;
  return a;
}

template<typename T>
T	templateMin(const T *a, int size)
{
  T		smallest;
  if (size <= 0)
    return 0;
  if (size == 1)
    return a[size];
  smallest = a[0];
  for (int it = 1; it < size; it += 1)
  {
    if (min<T>(a[it], smallest) == a[it])
      smallest = a[it];
  }
  return smallest;
}

int	nonTemplateMin(int * a, int size)
{
  int		smallest;
  if (size <= 0)
    return 0;
  if (size == 1)
    return a[size];
  smallest = a[0];
  for (int it = 1; it < size; it += 1)
  {
    if (min(a[it], smallest) == a[it])
      smallest = a[it];
  }
  return smallest;
}






#endif //CPP_D14M_EX02_HPP
