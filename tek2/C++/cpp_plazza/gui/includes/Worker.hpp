/*
** Worker.hpp for cpp_plazza in /home/gogo/rendu/tek2/cpp_plazza/includes/Worker.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Apr 16 18:39:13 2017 Gauthier Cler
** Last update Sun Apr 16 18:39:13 2017 Gauthier Cler
*/

#ifndef CPP_PLAZZA_WORKER_HPP
#define CPP_PLAZZA_WORKER_HPP

#include <regex>
#include <iostream>
#include "Thread.hpp"
#include "File.hpp"
#include "Command.hpp"
#include "XorCypher.hpp"
#include "CaesarCypher.hpp"
#include "XorCracker.hpp"

namespace plazza {

  /**
   * @brief Class used to execute tasks
   */
  class Worker {
  public:

    /**
     * @brief Class constructor
     */
    Worker();

    /**
     * @brief Class destructor
     */
    ~Worker() {};

    /**
     * @brief Class const copy constructor
     */
    Worker(const Worker &);

    /**
     * @brief Class copy constructor
     */
    Worker(Worker &);

    /**
     * @brief Start thread execution
     * @tparam Callable
     * @param func
     */
    template <typename Callable>
    void 	start(Callable func) {
      this->_thread = Thread(func);
    };

    /**
     * @brief Get Thread instance
     * @return Thread &
     */
    Thread		&getThread() const;

    /**
     * @brief Check if the Worker is busy
     * @return
     */
    bool		isBusy() const;

    /**
     * @brief Change worker working state
     * @param busy
     */
    void		setBusy(const bool busy);

    /**
     * @brief Send task to perform to the worker
     * @param fileName
     * @param type
     */
    void		performJob(const std::string &fileName, const Information type);

    /**
     * @brief Get the list of result found
     * @return std::vector<std::string>
     */
    std::vector<std::string>		getResults(void) const;
  private:
    void		display() const;
    void		searchResult(const Information type);
    void		setFileBuffer(const std::string &buffer);

    Thread		_thread;
    bool		_busy;
    File		_file;
    XorCypher		_xor;
    XorCracker		_cracker;
    CaesarCypher	_caesar;
    std::string		_fileBuffer;
    std::map<Information, std::regex> _regexes;
    std::vector<std::string>		_results;
  };
}

#endif //CPP_PLAZZA_WORKER_HPP
