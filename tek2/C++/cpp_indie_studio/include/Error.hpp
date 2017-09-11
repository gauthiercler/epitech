/*
** Error.hpp for cpp_indie_studio in /home/ventinc/epitech/cpp/cpp_indie_studio/include/Error.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Fri May 05 12:10:56 2017 Vincent DUSAUTOIR
** Last update Fri May 05 12:10:56 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_INDIE_STUDIO_ERROR_HPP
#define CPP_INDIE_STUDIO_ERROR_HPP

#include <string>
#include <exception>

namespace indie {
  class Error : public std::exception {
  public:
    /**
     * @brief Class constructor
     * @param message
     */
    Error(std::string const &message) : _message(message) {};
    /**
     * @brief Class destructor
     */
    virtual ~Error() noexcept {};
    /**
     * @brief get What value
     * @return const char *
     */
    const char *what() const throw() { return this->_message.c_str(); };

  private:
    std::string _message;
  };

/**
   * @brief Error Class used for IrrLichtWrapper
   */
  class IrrlichtError : public Error {
  public:
    /**
     * @brief Class constructor
     * @param message
     */
    IrrlichtError(std::string const &message) : Error("Irrlicht Error : " + message) {};
    /**
     * @brief Class destructor
     */
    virtual ~IrrlichtError() throw() {};
  };

  class GameError : public Error {
  public:
    GameError(std::string const &message) : Error("Game Error : " + message) {};
  };
}

#endif //CPP_INDIE_STUDIO_ERROR_HPP
