/*
** Mutex.cpp for cpp_plazza in /home/gogo/rendu/tek2/cpp_plazza/sources/Mutex.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Apr 12 15:34:45 2017 Gauthier Cler
** Last update Wed Apr 12 15:34:46 2017 Gauthier Cler
*/

#include <mutex>
#include "Mutex.hpp"

template <class T>
plazza::Mutex<T>::Mutex() {

}

template <class T>
plazza::Mutex<T>::~Mutex() {

}

template <class T>
void plazza::Mutex<T>::lock() {
  this->_mutex.lock();
}

template <class T>
void plazza::Mutex<T>::tryLock() {
  this->_mutex.try_lock();
}

template <class T>
void plazza::Mutex<T>::unlock() {
  this->_mutex.unlock();
}

template <class T>
T &plazza::Mutex<T>::get() {
  return this->_mutex;
}

template <class T>
plazza::Mutex<T>::Mutex(Mutex<T> &&) {

}

template <class T>
plazza::Mutex<T>::Mutex(const plazza::Mutex<T> &) {

}

template class plazza::Mutex<std::mutex>;
template class plazza::Mutex<std::recursive_mutex>;
template class plazza::Mutex<std::timed_mutex>;
template class plazza::Mutex<std::recursive_timed_mutex>;
