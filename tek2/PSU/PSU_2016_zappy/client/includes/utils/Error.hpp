/*
** Error.hpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/includes/utils/Error.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Jun 20 22:25:31 2017 Vincent DUSAUTOIR
** Last update Tue Jun 20 22:25:31 2017 Vincent DUSAUTOIR
*/

#ifndef PSU_2016_ZAPPY_ERROR_HPP
#define PSU_2016_ZAPPY_ERROR_HPP

#include <exception>
#include <string>

namespace zappy {
  class Error : public std::exception {
  public:
    Error(std::string const &message) : _message(message) {};
    virtual ~Error() noexcept {};
    virtual const char *what() const noexcept { return this->_message.c_str(); };

  protected:
    std::string _message;
  };

  class RessourcesManagerError : public Error {
  public:
    RessourcesManagerError(std::string const &message) : Error(std::string("RessourcesManagerError : " + message)) {};
    virtual ~RessourcesManagerError() noexcept {};
  };

  class DrawableError : public Error {
  public:
    DrawableError(std::string const &message) : Error(std::string("DrawableError : " + message)) {};
    virtual ~DrawableError() noexcept {};
  };

  class SocketError : public Error {
  public:
    SocketError(std::string const &message) : Error(std::string("SocketError : " + message)) {};
    virtual ~SocketError() noexcept {};
  };

  class SoundError : public Error {
  public:
    SoundError(std::string const &message) : Error(std::string("SoundError : " + message)) {};
    virtual ~SoundError() noexcept {};
  };
}
#endif //PSU_2016_ZAPPY_ERROR_HPP
