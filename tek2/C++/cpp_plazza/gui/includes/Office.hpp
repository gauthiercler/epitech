/*
** Kitchen.hpp for cpp_plazza in /home/ventinc/epitech/cpp/cpp_plazza/includes/Kitchen.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Apr 11 14:55:02 2017 Vincent DUSAUTOIR
** Last update Tue Apr 11 14:55:03 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_PLAZZA_KITCHEN_HPP
#define CPP_PLAZZA_KITCHEN_HPP

#include <iostream>		// Temporary include for debug-purpose
#include <sys/types.h>
#include <vector>
#include <chrono>
#include "ConnectorPipe.hpp"
#include "ThreadPool.hpp"

namespace			plazza {

  /*
   * Class used for managing Workers
   */
  class				Office {

    pid_t			_pid;
    size_t			_capacity;
    std::time_t			_unactiveSpan;
    ConnectorPipe		_serverStream;
    ConnectorPipe		_privateStream;
    ThreadPool			_workersPool;
    size_t			_freeTaskSpots;
    std::string			_privateKey;

  public:

    /**
     * @brief Class constructor
     * @param capacity
     */
    Office(const unsigned int capacity = 0);

    /**
     * @brief operator =
     * @param office
     * @return Office &
     */
    Office& operator=(const Office &office);

    /**
     * @brief Class Move constructor
     * @param office
     */
    Office(Office &&office);

    /**
     * @brief Class destructor
     */
    ~Office();

    // Getters & Setter

    /**
     * @brief Get Office process pid
     * @return pid_t
     */
    pid_t			getPid() const;

    /**
     * @brief get Office capacity
     * @return size_t
     */
    size_t			getCapacity() const;

    /**
     * @brief get Office private key
     * @return const std::string
     */
    const std::string		&getPrivateKey() const;

    /**
     * @brief Get the number of inactive workers
     * @return size_t
     */
    size_t			getFreeWorkers() const;

    /**
     * @brief Get the time since no workers are working
     * @return std::time_t
     */
    std::time_t			getUnactiveSpan() const;

    /**
     * @brief Get number of available tasks
     * @return size_t
     */
    size_t			getFreeTaskSpots() const;

    /**
     * @brief Set process pid
     * @param pid
     */
    void			setPid(const pid_t pid);

    /**
     * @brief Set Office capacity
     * @param capacity
     */
    void			setCapacity(const unsigned int capacity);

    /**
     * @brief Set Office private key
     * @param key
     */
    void			setPrivateKey(const std::string &key);

    /**
     * @brief set number of available tasks
     * @param amount
     */
    void			setFreeTaskSpots(const size_t amount);

    // Initialization

    /**
     * @brief init the Office
     */
    void			init(void);

    /**
     * @brief Start the office
     */
    void			run(void);

    /**
     * @brief Get task for the private pipe
     */
    void			getTask(void);
    void			assignTask(const Data &data);

    /**
     * @brief Finish the task and send it to the server
     */
    void			completeTask(void);

    /**
     * @brief Check if the office is active
     * @return bool
     */
    bool			isActive(void) const;

    /**
     * @brief Close the office
     */
    void			close(void);

    /**
     * @brief Function called when a worker finish a task
     */
    void			workerCallback(const std::vector<std::string> &) const;

  };
}

#endif //CPP_PLAZZA_KITCHEN_HPP
