/*
** Parts.h for cpp_d07m in /home/gogo/rendu/tek2/cpp_d07a/ex01/Parts.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 10 18:55:18 2017 Gauthier CLER
** Last update Tue Jan 10 18:55:18 2017 Gauthier CLER
*/


#ifndef CPP_D07M_PARTS_H
#define CPP_D07M_PARTS_H


#include <string>

class Arms {
private:
  std::string	_serial;
  bool		_functionnal;
public:
  Arms(std::string const & serial = "A-01", bool functionnal = true);
  ~Arms();
  bool isFunctionnal() const;
  std::string serial() const;
  void informations() const;
};

class Legs{
private:
  std::string	_serial;
  bool		_functionnal;
public:
  Legs(std::string const & serial = "L-01", bool functionnal = true);
  ~Legs();
  bool isFunctionnal() const;
  std::string serial() const;
  void informations() const;
};

class Head{
private:
  std::string	_serial;
  bool		_functionnal;
public:
  Head(std::string const & serial = "H-01", bool functionnal = true);
  ~Head();
  bool isFunctionnal() const;
  std::string serial() const;
  void informations() const;
};


#endif //CPP_D07M_PARTS_H
