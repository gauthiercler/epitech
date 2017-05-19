/*
** Command.hpp for cpp_plazza in /home/ventinc/epitech/cpp/cpp_plazza/includes/Command.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Apr 11 15:25:42 2017 Vincent DUSAUTOIR
** Last update Tue Apr 11 15:25:42 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_PLAZZA_COMMAND_HPP
#define CPP_PLAZZA_COMMAND_HPP

#include <string>
#include <vector>
#include <map>

/**
 * @brief list of possibles Information to search
 */
enum class			Information {
  PHONE_NUMBER,
  EMAIL_ADDRESS,
  IP_ADDRESS,
  UNKNOWN
};

namespace				plazza {

  /**
   * @brief Class used for managing Command
   */
  class					Command {
    Information				_type;
    std::vector<std::string>		_args;
    std::map<std::string, Information>	_stringCommandType;

  public:

    /**
     * @brief Class constructor
     */
    Command();

    /**
     * @brief Class destructor
     */
    ~Command();

    /**
     * @brief Get Command Type
     * @return Information
     */
    Information				getType() const;

    /**
     * @brief Get Command arguments
     * @return const std::vector<std::string>
     */
    const std::vector<std::string>	&getArgs() const;

    /**
     * @brief Define command type
     * @param type
     */
    void				setType(const Information type);

    /**
     * @brief Define command type using a literal string
     * @param type
     */
    void				setType(const std::string &type);

    /**
     * @brief Define command arguments
     * @param args
     */
    void				setArgs(const std::vector<std::string> &args);

    /**
     * @brief reset command (arguments, type)
     */
    void				reset();

    /**
     * @brief Debug display of command
     */
    void				display() const;
  };
}

#endif //CPP_PLAZZA_COMMAND_HPP
