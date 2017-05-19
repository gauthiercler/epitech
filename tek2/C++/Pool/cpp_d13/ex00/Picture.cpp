/*
** Picture.cpp for cpp_d09 in /home/gogo/rendu/tek2/cpp_d13/ex00/Picture.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jan 16 09:33:39 2017 Gauthier CLER
** Last update Mon Jan 16 09:33:40 2017 Gauthier CLER
*/


#include <sstream>
#include <fstream>
#include "Picture.h"

Picture::Picture(const std::string &file) {
  if (file =="")
    this->data = "";
  else
    this->getPictureFromFile(file);
}


Picture::~Picture() {

}

bool Picture::getPictureFromFile(const std::string &fileName) {
  std::ifstream		file;
  std::stringstream	stream;

  file.open(fileName.c_str());
  if (file.is_open()){
    stream << file.rdbuf();
    this->data = stream.str();
    return true;
  }
  this->data = "ERROR";
  return false;
}
