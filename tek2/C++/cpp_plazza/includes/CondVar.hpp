/*
** CondVar.hpp for cpp_plazza in /home/gogo/rendu/tek2/cpp_plazza/includes/CondVar.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Apr 12 16:06:08 2017 Gauthier Cler
** Last update Wed Apr 12 16:06:08 2017 Gauthier Cler
*/

#ifndef CPP_PLAZZA_CONDVAR_HPP
#define CPP_PLAZZA_CONDVAR_HPP

#include <condition_variable>
#include "Mutex.hpp"

namespace plazza {

  /**
   * @brief Conditional variable encapsulation class
   */
  class CondVar {
  public:
    /**
     * @brief Class constructor
     */
    CondVar() {};

    /**
     * @brief Class Move constructor
     */
    CondVar(CondVar &&) {};

    /**
     * @brief Class destructor
     */
    ~CondVar() {};

    /**
     * @brief Wait until notified
     * @tparam Lock
     * @param lock
     */
    template <class Lock>
    void	wait(Lock&lock) {
      this->_var.wait(lock);
    }

    /**
     * @brief Wait but only lock if Predicate return false
     * @tparam Lock
     * @tparam Predicate
     * @param lock
     * @param pred
     */
    template <class Lock, class Predicate>
    void	wait(Lock&lock, Predicate pred) {
      this->_var.wait(lock, pred);
    };

    /**
     * @brief Wait for timeout or until notified
     * @tparam Lock
     * @tparam Rep
     * @tparam Period
     * @param lock
     * @param relTime
     * @return std::cv_status
     */
    template <class Lock, class Rep, class Period>
    std::cv_status waitFor(Lock&lock, const std::chrono::duration<Rep, Period>& relTime) {
      return this->_var.wait_for(lock, relTime);
    };

    /**
     * @brief Wait for timeout or until notified only if Predicate return false
     * @tparam Lock
     * @tparam Rep
     * @tparam Period
     * @tparam Predicate
     * @param lock
     * @param relTime
     * @param pred
     * @return bool
     */
    template <class Lock, class Rep, class Period, class Predicate>
      bool	waitFor(Lock&lock, const std::chrono::duration<Rep, Period>& relTime, Predicate pred) {
      return this->_var.wait_for(lock, relTime, pred);
    };

    /**
     * @brief Wait until notified or time point
     * @tparam Lock
     * @tparam Clock
     * @tparam Duration
     * @param lock
     * @param absTime
     * @return std::cv_status
     */
    template <class Lock, class Clock, class Duration>
      std::cv_status waitUntil(Lock&lock, const std::chrono::time_point<Clock, Duration>& absTime) {
      return this->_var.wait_until(lock, absTime);
    };

    /**
     * @brief Wait until notified or time point only if Predicate return false
     * @tparam Lock
     * @tparam Clock
     * @tparam Duration
     * @tparam Predicate
     * @param lock
     * @param absTime
     * @param pred
     * @return bool
     */
    template <class Lock, class Clock, class Duration, class Predicate>
      bool	waitUntil(Lock&lock, const std::chrono::time_point<Clock, Duration> &absTime, Predicate pred) {
      return this->_var.wait_until(lock, absTime, pred);
    };

    /**
     * @brief Notify one
     */
    void	notifyOne() noexcept {
      this->_var.notify_one();
    }

    /**
     * @brief Notify all
     */
    void	notifyAll() noexcept {
      this->_var.notify_all();
    }

  private:
    std::condition_variable_any	_var;
  };
}

#endif //CPP_PLAZZA_CONDVAR_HPP
