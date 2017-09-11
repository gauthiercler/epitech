/*
** IABinding.hpp for cpp_indie_studio in /home/gogo/rendu/tek2/cpp_indie_studio/include/core/IABinding.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jun 16 11:26:59 2017 Gauthier Cler
** Last update Fri Jun 16 11:27:00 2017 Gauthier Cler
*/

#ifndef CPP_INDIE_STUDIO_IABINDING_HPP
# define CPP_INDIE_STUDIO_IABINDING_HPP

#include <pybind11/pybind11.h>
#include <pybind11/embed.h>
#include <atomic>
#include <mutex>
#include <game/IA.hpp>

namespace indie {
  class IABinding {
    static IABinding	singleton;
    IABinding();
    pybind11::scoped_interpreter	_guard;
    pybind11::module			_moduleEasy;
    pybind11::module			_moduleHard;
    std::mutex				_mutex;
    void 				defineBindingAttr(pybind11::module &module);
  public:
    IABinding(const IABinding&) = delete;
    IABinding& operator=(const IABinding&) = delete;
    static IABinding &get();
    pybind11::module &getModule(IADiff diff);
    std::mutex	&getMutex() { return _mutex; };
  };
}

#endif /* !CPP_INDIE_STUDIO_IABINDING_HPP*/
