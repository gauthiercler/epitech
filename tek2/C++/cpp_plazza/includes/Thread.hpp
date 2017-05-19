/*
** Thread.hpp for cpp_plazza in /home/gogo/rendu/tek2/cpp_plazza/sources/Thread.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Apr 12 15:17:28 2017 Gauthier Cler
** Last update Wed Apr 12 15:17:28 2017 Gauthier Cler
*/

/*
** Thread.hpp for cpp_plazza in /home/gogo/rendu/tek2/cpp_plazza/includes/Thread.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Apr 11 16:23:37 2017 Gauthier Cler
** Last update Tue Apr 11 16:23:37 2017 Gauthier Cler
*/

#ifndef CPP_PLAZZA_THREAD_HPP
#define CPP_PLAZZA_THREAD_HPP

#include <thread>

namespace		plazza {

  /**
   * @brief Class for std::thread encapsulation
   */
  class			Thread {
  public:

    /**
     * @brief Default class constructor. The object created is not a Thread
     */
    Thread() noexcept;

    /**
     * @brief Class constructor
     * @tparam Fn
     * @tparam Args
     * @param fn
     * @param args
     */
    template <typename Fn, typename ... Args>
    explicit Thread(Fn&& fn, Args&&... args) { this->_thread = std::thread(fn, args...); };

    /**
     * @brief Class copy constructor (deleted)
     */
    Thread(Thread&) = delete;

    /**
     * @brief Class const copy constructor (deleted)
     */
    Thread(const Thread&) = delete;

    /**
     * @brief Class move constructor
     * @param x
     */
    Thread(Thread &&x) noexcept;

    /**
     * @brief Class destructor
     */
    ~Thread();

    /**
     * @brief Operator=. Used to move Thread instance.
     * @param rhs
     * @return Thread &
     */
    Thread 				&operator=(Thread && rhs);

    /**
     * @brief Get thread instance
     * @return std::thread &
     */
    std::thread				&get();

    /**
     * @brief Get thread id
     * @return std::thread::id
     */
    std::thread::id			getId() const;

    /**
     * @brief Define if a thread is joinable
     * @return bool
     */
    bool				joinable();

    /**
     * @brief Join a thread
     */
    void				join();

    /**
     * @brief Detach a thread
     */
    void				detach();

    /**
     * @brief Swap a thread
     * @param other
     */
    void				swap(Thread &other);

    /**
     * @brief Swap thread
     * @return std::thread::native_handle_type
     */
    std::thread::native_handle_type 	native_handle();
  private:
    std::thread				_thread;
  };


}

#endif //CPP_PLAZZA_THREAD_HPP

