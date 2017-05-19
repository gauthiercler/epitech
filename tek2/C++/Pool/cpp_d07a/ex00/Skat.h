/*
** Skat.h for cpp_d07m in /home/gogo/rendu/tek2/cpp_d07a/ex00/Skat.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 10 18:13:02 2017 Gauthier CLER
** Last update Tue Jan 10 18:13:04 2017 Gauthier CLER
*/

#ifndef CPP_D07M_SKAT_H
#define CPP_D07M_SKAT_H


#include <string>

class Skat {
public:
  Skat(std::string const&  name = "bob", int stimPaks = 15);
  ~Skat();

public:
  int & stimPaks();
  const std::string & name();

public:
  void shareStimPaks(int number, int & stock);
  void	addStimPaks(unsigned int number);
  void useStimPaks();

public:
  void	status();

private:
  std::string	_name;
  int		_stimPaks;
};


#endif //CPP_D07M_SKAT_H
