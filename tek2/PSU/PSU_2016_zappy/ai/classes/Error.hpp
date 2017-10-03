/*
** Error.hpp for PSU_2016_zappy in /home/gogo/rendu/tek2/PSU_2016_zappy/ai/classes/Error.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jun 19 21:37:23 2017 Gauthier Cler
** Last update Mon Jun 19 21:37:23 2017 Gauthier Cler
*/

#ifndef PSU_2016_ZAPPY_ERROR_HPP
#define PSU_2016_ZAPPY_ERROR_HPP

#include <stdexcept>
#include <iostream>

namespace ai {

  class Error : std::exception {
  public:
    Error(std::string const &message) : _message(message)
    {std::cout << message << std::endl;};
    virtual ~Error() noexcept
    {};
    const char *what() const throw() { return _message.c_str(); }
  protected:
    const std::string &_message;
  };
}

#endif //PSU_2016_ZAPPY_ERROR_HPP
