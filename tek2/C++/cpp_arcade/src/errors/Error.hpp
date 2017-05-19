/*
** Error.hpp for cpp_arcade in /home/gogo/rendu/tek2/cpp_arcade/src/errors/Error.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sat Mar 25 18:43:18 2017 Gauthier Cler
** Last update Sat Mar 25 18:43:18 2017 Gauthier Cler
*/

#ifndef CPP_ARCADE_ERRORS_HPP
#define CPP_ARCADE_ERRORS_HPP

#include <string>

namespace arcade {

  class Error : public std::exception {
  public:
    Error(std::string const &message) : _message(message) {};
    virtual ~Error() throw() {};
    const char *what() const throw() { return this->_message.c_str(); };

  private:
    std::string	_message;
  };

  class DynLoaderError : public Error
  {
  public:
    DynLoaderError(std::string const &message) : Error(message) {};
    virtual ~DynLoaderError() throw() {};
  };
}


#endif //CPP_ARCADE_ERRORS_HPP
