/*
** ex00.hpp for cpp_d14m in /home/gogo/rendu/tek2/cpp_d15/ex00/ex00.hpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Jan 18 10:13:32 2017 Gauthier CLER
** Last update Wed Jan 18 10:13:32 2017 Gauthier CLER
*/

#ifndef CPP_D14M_EX00_HPP
#define CPP_D14M_EX00_HPP

template <typename T>
void 	swap(T &a, T &b)
{
  T c = a;
  a = b;
  b = c;
}

template <typename T>
T	min(T a, T b)
{
  if (a < b)
    return a;
  return b;
}


template <typename T>
T	max(T a, T b)
{
  if (a > b)
    return a;
  return b;
}

template <typename T>
T	add(T a, T b)
{
  return (a + b);
}



#endif //CPP_D14M_EX00_HPP
