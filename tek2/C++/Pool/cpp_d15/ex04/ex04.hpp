/*
** ex04.hpp for cpp_d14m in /home/gogo/rendu/tek2/cpp_d15/ex04/ex04.hpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Jan 18 14:11:25 2017 Gauthier CLER
** Last update Wed Jan 18 14:11:25 2017 Gauthier CLER
*/

#ifndef CPP_D14M_EX04_HPP
#define CPP_D14M_EX04_HPP


template <typename T>
bool	equal(const T &a, const T &b);

template <typename T>
class Tester {
public:
  Tester();
  ~Tester();
  bool		equal(const T &a, const T &b) const;
};



#endif //CPP_D14M_EX04_HPP
