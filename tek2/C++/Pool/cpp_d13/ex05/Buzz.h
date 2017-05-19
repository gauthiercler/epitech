/*
** Buzz.h for cpp_d09 in /home/gogo/rendu/tek2/cpp_d13/ex02/Buzz.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jan 16 11:08:22 2017 Gauthier CLER
** Last update Mon Jan 16 11:08:23 2017 Gauthier CLER
*/


#ifndef CPP_D09_BUZZ_H
#define CPP_D09_BUZZ_H


#include "Toy.h"

class Buzz : public Toy {
public:
  Buzz(std::string name, std::string ascii = "buzz.txt");
  virtual ~Buzz();
  virtual bool speak(const std::string &statement);
  virtual bool	speak_es(const std::string &statement);
};


#endif //CPP_D09_BUZZ_H
