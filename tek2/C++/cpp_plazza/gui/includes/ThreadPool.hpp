/*
** ThreadPool.hpp for cpp_plazza in /home/gogo/rendu/tek2/cpp_plazza/includes/ThreadPool.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sat Apr 15 15:27:11 2017 Gauthier Cler
** Last update Sat Apr 15 15:27:11 2017 Gauthier Cler
*/

#ifndef CPP_PLAZZA_THREADPOOL_HPP
#define CPP_PLAZZA_THREADPOOL_HPP

#include <vector>
#include <mutex>
#include <queue>
#include "Thread.hpp"
#include "Mutex.hpp"
#include "CondVar.hpp"
#include "Worker.hpp"
#include "Command.hpp"

namespace plazza {

  /**
   * @brief Class used to manage Thread
   */
  class ThreadPool {
  public:

    /**
     * @brief Class constructor
     * @param callBack
     */
    ThreadPool(std::function< void (const std::vector<std::string> &)> callBack);

    /**
     * @brief Class move constructor
     * @param threadPool
     */
    ThreadPool(ThreadPool &&threadPool);

    /**
     * @brief Class destructor
     */
    ~ThreadPool();

    /**
     * @brief Add the number of workers to the pool
     * @param nbWorkers
     */
    void	createWorkers(size_t nbWorkers);

    /**
     * @brief Get the number of total workers
     * @return size_t
     */
    size_t	getNbWorkers() const;

    /**
     * @brief Get the number of free workers
     * @return
     */
    size_t	getNbFreeWorkers() const;

    /**
     * @brief Get the Queue task length
     * @return size_t
     */
    size_t	getQueueLength() const;

    /**
     * @brief Add a job to the queue
     * @param fileName
     * @param type
     */
    void	addJob(const std::string &fileName, Information type);

    /**
     * @brief Stop the pool execution
     */
    void	stop();
  private:

    /**
     * @brief Wait for a job as worker
     */
    void	waitJob();

    /**
     * @brief Get the current Thread worker
     * @return Worker &
     */
    Worker	&getWorker();

    /**
     * @brief Set current worker working state
     * @param state
     */
    void	setWorkerState(bool state);

    std::vector<Worker>							_workers;
    Mutex<std::mutex>							_queueLock;
    std::queue<std::pair<std::string, Information>>			_jobsQueue;
    CondVar								_condition;
    bool								_stop;
    std::function<void (const std::vector<std::string> &)>			_callback;
    //Thread Stop (cond var) & Join all
  };
}


#endif //CPP_PLAZZA_THREADPOOL_HPP
