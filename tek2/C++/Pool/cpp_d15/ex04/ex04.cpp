/*
** ex04.cpp for cpp_d14m in /home/gogo/rendu/tek2/cpp_d15/ex04/ex04.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Jan 18 14:11:29 2017 Gauthier CLER
** Last update Wed Jan 18 14:11:29 2017 Gauthier CLER
*/

#include <string>
#include "ex04.hpp"

template <typename T>
bool equal(const T &a, const T &b){
  return a == b;
}

template bool equal<int>(const int &a, const int &b);
template bool equal<float>(const float &a, const float &b);
template bool equal<double>(const double &a, const double &b);
template bool equal<std::string>(const std::string &a, const std::string &b);

template <class T>Tester<T>::Tester(){

}

template <class T> Tester<T>::~Tester() {

}


template <class T>
bool Tester<T>::equal(const T &a, const T &b) const{
  return a == b;
}

template class Tester<int>;
template class Tester<float>;
template class Tester<double>;
template class Tester<std::string>;
