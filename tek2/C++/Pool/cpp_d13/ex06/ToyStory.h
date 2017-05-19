/*
** ToyStory.h for cpp_d13 in /home/gogo/rendu/tek2/cpp_d13/ex06/ToyStory.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jan 16 14:58:09 2017 Gauthier CLER
** Last update Mon Jan 16 14:58:09 2017 Gauthier CLER
*/


#ifndef CPP_D13_TOYSTORY_H
#define CPP_D13_TOYSTORY_H


#include <string>
#include "Toy.h"

class ToyStory {
public:
  static void		tellMeAStory(const char *fileName, Toy &a, bool (Toy::*func1)(const std::string &string), Toy &b, bool (Toy::*func2)(const std::string &string));
};


#endif //CPP_D13_TOYSTORY_H
