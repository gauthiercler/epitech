/*
** ex06.hpp for cpp_d14m in /home/gogo/rendu/tek2/cpp_d15/ex06/ex06.hpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Jan 18 18:27:01 2017 Gauthier CLER
** Last update Wed Jan 18 18:27:03 2017 Gauthier CLER
*/

#ifndef CPP_D15_EX06_HPP
#define CPP_D15_EX06_HPP

#include <sstream>

template <typename T>
std::string	getType(T type)
{
  (void)type;
  return "[???]";
}

std::string	getType(int type)
{
  std::stringstream	response;

  response << "[int:" << type << "]";
  return response.str();
}

std::string	getType(float type)
{
  std::stringstream	response;

  response << "[float:" << type << "f]";
  return response.str();
}

std::string	getType(std::string type)
{
  return "[string:\"" + type + "\"]";
}

template <typename T, typename U = T>
struct Tuple{
public:
  T	a;
  U	b;
  std::string	toString() const{
    return "[TUPLE " + getType(a) + " " + getType(b) + "]";
  };
};

#endif //CPP_D15_EX06_HPP
