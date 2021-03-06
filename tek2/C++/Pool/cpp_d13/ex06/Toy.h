/*
** Toy.h for cpp_d09 in /home/gogo/rendu/tek2/cpp_d13/ex00/Toy.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jan 16 09:33:06 2017 Gauthier CLER
** Last update Mon Jan 16 09:33:06 2017 Gauthier CLER
*/


#ifndef CPP_D09_TOY_H
#define CPP_D09_TOY_H


#include "Picture.h"

class Toy {
public:
  enum ToyType{
    BASIC_TOY,
    ALIEN,
    BUZZ,
    WOODY
  };
  Toy();
  Toy(const ToyType type, std::string name, std::string fileName);
  virtual ~Toy();
  ToyType		getType() const;
  std::string		getName() const;
  void			setName(std::string name);
  bool			setAscii(std::string name);
  std::string		getAscii() const;
  Toy(const Toy &toy);
  Toy &operator=(const Toy &picture);
  Toy &operator<<(const std::string &string);
  virtual bool	speak(const std::string &statement);
  virtual bool	speak_es(const std::string &statement);

  class Error{
  public:
    enum ErrorType{
      UNKNOWN,
      PICTURE,
      SPEAK
    };
    std::string	what();
    std::string	where();
    ErrorType 	type;
    void	setWhat(std::string what);
    void	setWhere(std::string where);
    void	setErrorType(Toy::Error::ErrorType);
    std::string	getWhat() const;
    std::string	getWhere() const;
    ErrorType 	getErrorType() const;

  private:
    std::string	_what;
    std::string	_where;
  };
  Error		getLastError();

private:
  Error			_error;
  const ToyType  	_type;
  std::string		_name;
  Picture		*_picture;
};

std::ostream &operator<<(std::ostream &stream, const Toy &toy);

#endif //CPP_D09_TOY_H
