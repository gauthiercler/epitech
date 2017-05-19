/*
** Reception.hpp for cpp_plazza in /home/ventinc/epitech/cpp/cpp_plazza/includes/Reception.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Apr 11 14:48:18 2017 Vincent DUSAUTOIR
** Last update Tue Apr 11 14:48:18 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_PLAZZA_RECEPTION_HPP
#define CPP_PLAZZA_RECEPTION_HPP

#include <vector>
#include "Office.hpp"
#include "ProcessManager.hpp"
#include "ConnectorPipe.hpp"
#include <QApplication>
#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace			plazza {

  /**
   * @brief Class used for managing Offices
   */
  class				Reception {

    std::vector<Office>		_offices;
    ProcessManager		_processPool;
    ConnectorPipe		_serverStream;
    ConnectorPipe		_officeStream;
    unsigned int		_officeCapacity;

    // ProcessManager
    // Get kill id etc by socket from process if he's done. Send Office object to processPool to remove it.

    // TODO :
    // TaskManager for a two-way bind on commands/offices, so that we can handle crashing processes not doing their work.

  public:

    /**
     * @brief Class constructor
     * @param officeCapacity
     */
    Reception(const unsigned int officeCapacity = 5);

    /**
     * @brief Class destructor
     */
    ~Reception();

    /**
     * @brief Get the office capacity
     * @return
     */
    unsigned int		getOfficeCapacity() const;

    /**
     * @brief Create an office
     */
    void			createOffice();

    /**
     * @brief remove the office specified as office_id
     * @param office_id
     */
    void			removeOffice(const pid_t office_id);

    /**
     * @brief run the office
     */
    void			run(int ac, char *av[]);

    /**
     * @brief Flush the server data
     */
    void			flushServerData(MainWindow &window);

    /**
     * @brief Assign a task to the queue
     * @param type
     * @param value
     */
    void			assignTask(const Information type, const std::string &value);

    /**
     * @brief Send a task
     * @param office
     * @param Type
     * @param value
     */
    void			sendTask(const plazza::Office &office, const Information Type, const std::string &value);

    /**
     * @brief Called when a task has ended
     * @param office_id
     */
    void			completeTask(const pid_t office_id);

    /**
     * @brief Close the office
     */
    void			close(MainWindow &window);
  };

}

#endif //CPP_PLAZZA_RECEPTION_HPP
