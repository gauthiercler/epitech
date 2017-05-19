/*
** CommandManager.hpp for cpp_plazza in /home/ventinc/epitech/cpp/cpp_plazza/includes/CommandManager.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Apr 11 15:22:46 2017 Vincent DUSAUTOIR
** Last update Tue Apr 11 15:22:46 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_PLAZZA_COMMANDMANAGER_HPP
#define CPP_PLAZZA_COMMANDMANAGER_HPP

#include <regex>
#include "Command.hpp"

namespace		plazza {
  /**
   * @brief Command Manager Class
   */
  class			CommandManager {
    Command		_command;
    std::regex		_regex;

  public:
    /**
     * @brief Class constructor
     */
    CommandManager();

    /**
     * @brief Class destructor
     */
    ~CommandManager();

    /**
     * @brief Get parsed command
     * @return const Command
     */
    const Command	&getCommand() const;

    /**
     * @brief Parse command provided as parameter
     * @param command
     */
    void		parseCommand(const std::string &command);

  };
}

#endif //CPP_PLAZZA_COMMANDMANAGER_HPP
