/*
** Picture.h for cpp_d09 in /home/gogo/rendu/tek2/cpp_d13/ex00/Picture.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jan 16 09:33:30 2017 Gauthier CLER
** Last update Mon Jan 16 09:33:32 2017 Gauthier CLER
*/


#ifndef CPP_D09_PICTURE_H
#define CPP_D09_PICTURE_H


#include <string>

class Picture {
public:
  std::string	data;
  ~Picture();
  bool getPictureFromFile(const std::string &file);
  Picture(const std::string& file = "");
  Picture(const Picture &picture);

  Picture &operator=(const Picture &picture);
};


#endif //CPP_D09_PICTURE_H
