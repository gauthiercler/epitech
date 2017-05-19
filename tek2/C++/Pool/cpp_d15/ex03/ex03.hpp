/*
** ex03.hpp for cpp_d14m in /home/gogo/rendu/tek2/cpp_d15/ex03/ex03.hpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Jan 18 13:54:55 2017 Gauthier CLER
** Last update Wed Jan 18 13:54:55 2017 Gauthier CLER
*/

#ifndef CPP_D14M_EX03_HPP
#define CPP_D14M_EX03_HPP


#include <iostream>

template<typename T>
void	print(const T &elem)
{
  std::cout << elem << std::endl;
}

template<typename T>
void foreach(const T *table, void (*ptr)(const T &elem), const int &size)
{
  for (int i = 0; i < size; i += 1)
    ptr(table[i]);
}


#endif //CPP_D14M_EX03_HPP
