/*
** sickkoala.h for cpp_d06 in /home/gogo/rendu/tek2/cpp_d06/ex02/sickkoala.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jan 09 12:06:57 2017 Gauthier CLER
** Last update Mon Jan 09 12:07:00 2017 Gauthier CLER
*/


#ifndef CPP_D06_SICKKOALA_H
# define CPP_D06_SICKKOALA_H

#include <string>
#include <iostream>

class SickKoala
{
private:
  std::string	name;
  std::string 	formatName();

public:
  SickKoala(std::string name);
  ~SickKoala();
  void 		poke();
  int 		takeDrug(std::string drug);
  void		overDrive(std::string);
};

#endif //CPP_D06_SICKKOALA_H
