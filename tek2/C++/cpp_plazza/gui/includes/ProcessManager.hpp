/*
** ProcessPool.hpp for cpp_plazza in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_plazza/includes/ProcessPool.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Tue Apr 11 22:06:30 2017 Anas Buyumad
** Last update Tue Apr 11 22:06:30 2017 Anas Buyumad
*/

#ifndef CPP_PLAZZA_PROCESSPOOL_HPP
#define CPP_PLAZZA_PROCESSPOOL_HPP

#include "Office.hpp"
#include "Error.hpp"

namespace			plazza {

  /**
   * @brief Class used for managing processes
   */
  class				ProcessManager {

    std::vector<pid_t>		_processes;

  public:

    /**
     * @brief Class constructor
     */
    ProcessManager();

    /**
     * @brief Class destructor
     */
    ~ProcessManager();

    /**
     * @brief create an Office
     * @param office
     */
    void			spawn(Office &office);

    /**
     * @brief terminate the office
     * @param office
     */
    void			kill(const Office &office);

  };

}

#endif //CPP_PLAZZA_PROCESSPOOL_HPP
