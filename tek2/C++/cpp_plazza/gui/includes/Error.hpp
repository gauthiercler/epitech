/*
** Error.hpp for cpp_plazza in /home/ventinc/epitech/cpp/cpp_plazza/includes/Error.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Apr 11 15:27:27 2017 Vincent DUSAUTOIR
** Last update Tue Apr 11 15:27:27 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_PLAZZA_ERROR_HPP
#define CPP_PLAZZA_ERROR_HPP

#include <string>
#include <exception>

namespace		plazza {
  /**
   * @brief Plazza standard error Class
   */
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
    virtual ~Error() throw() {};
    /**
     * @brief get What value
     * @return const char *
     */
    const char *what() const throw() { return this->_message.c_str(); };

  private:
    std::string _message;
  };

  /**
   * @brief Error Class used for Command
   */
  class CommandError : public Error {
  public:
    /**
     * @brief Class constructor
     * @param message
     */
    CommandError(std::string const &message) : Error("Command Error : " + message) {};
    /**
     * @brief Class destructor
     */
    virtual ~CommandError() throw() {};
  };
}

#endif //CPP_PLAZZA_ERROR_HPP
