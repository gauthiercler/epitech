/*
** Error.hpp for cpp_nanotekspice in /home/gogo/rendu/tek2/cpp_nanotekspice/sources/classes/errors/Error.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jan 30 15:26:21 2017 Gauthier Cler
** Last update Mon Jan 30 15:26:21 2017 Gauthier Cler
*/

#ifndef CPP_NANOTEKSPICE_ERRORS_HPP
#define CPP_NANOTEKSPICE_ERRORS_HPP

#include <string>

namespace nts {

  class Error : public std::exception {
  public:
    Error(std::string const &message) : _message(message) {};
    virtual ~Error() throw() {};
    const char *what() const throw() { return this->_message.c_str(); };

  private:
    std::string	_message;
  };
}


#endif //CPP_NANOTEKSPICE_ERRORS_HPP
