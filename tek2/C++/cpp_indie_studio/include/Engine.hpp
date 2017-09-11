/*
** Engine.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/Engine.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  sam. juin 10 14:22:38 2017 Anthony LECLERC
** Last update sam. juin 10 14:22:38 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_ENGINE_HPP
#define CPP_INDIE_STUDIO_ENGINE_HPP

#include "IrrlichtWrapper.hpp"

namespace indie {
  class Engine {
  private:
    static std::unique_ptr<IrrlichtWrapper> IrrlichtEngine;

  public:
    static IrrlichtWrapper &get()
    {
      if (IrrlichtEngine == nullptr)
	IrrlichtEngine = std::make_unique<IrrlichtWrapper>();
      return (*IrrlichtEngine);
    };
  };
}

#endif //CPP_INDIE_STUDIO_ENGINE_HPP
