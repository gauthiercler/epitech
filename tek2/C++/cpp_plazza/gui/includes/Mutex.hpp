/*
** Mutex.hpp for cpp_plazza in /home/gogo/rendu/tek2/cpp_plazza/Mutex.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Apr 12 14:39:08 2017 Gauthier Cler
** Last update Wed Apr 12 14:39:08 2017 Gauthier Cler
*/

#ifndef CPP_PLAZZA_MUTEX_HPP
#define CPP_PLAZZA_MUTEX_HPP

namespace		plazza {
  /**
   * @brief Template class for Mutex encapsulation
   * @tparam T
   */
  template <class T>
  class 		Mutex {
  public:
    /**
     * @brief Class constructor
     */
    Mutex();

    /**
     * @brief Class copy constructor
     */
    Mutex(const Mutex<T> &);

    /**
     * @brief Class move constructor
     * @param mutex
     */
    Mutex(Mutex &&mutex);

    /**
     * @brief Class destructor
     */
    ~Mutex();

    /**
     * @brief Lock mutex
     */
    void		lock();

    /**
     * @brief Lock mutex if not locked
     */
    void		tryLock();

    /**
     * @brief Unlock mutex
     */
    void		unlock();

    /**
     * @brief Get template mutex instance
     * @return T
     */
    T			&get();
  private:
    T			_mutex;
  };
}



#endif //CPP_PLAZZA_MUTEX_HPP
