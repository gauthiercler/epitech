/*
** BF_Translator.h for cpp_d16 in /home/gogo/rendu/tek2/cpp_d16/ex03/BF_Translator.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jan 19 16:53:12 2017 Gauthier CLER
** Last update Thu Jan 19 16:53:12 2017 Gauthier CLER
*/

#ifndef CPP_D16_BF_TRANSLATOR_HPP
#define CPP_D16_BF_TRANSLATOR_HPP


#include <string>

class BF_Translator {
public:
  BF_Translator();
  ~BF_Translator();
  int translate(std::string in, std::string out);
};


#endif //CPP_D16_BF_TRANSLATOR_HPP
