
/*
** IABinding.cpp for cpp_indie_studio in /home/gogo/rendu/tek2/cpp_indie_studio/sources/core/IABinding.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jun 16 11:28:03 2017 Gauthier Cler
** Last update Fri Jun 16 11:28:03 2017 Gauthier Cler
*/

#include <core/IABinding.hpp>
#include <game/IA.hpp>


indie::IABinding indie::IABinding::singleton;


indie::IABinding::IABinding() {
  _moduleEasy = pybind11::module::import("basicIA");
  this->defineBindingAttr(_moduleEasy);
}

indie::IABinding &indie::IABinding::get() {
  return singleton;
}

pybind11::module &indie::IABinding::getModule(IADiff) {
    return _moduleEasy;
}

void indie::IABinding::defineBindingAttr(pybind11::module &module) {
  pybind11::class_<Position>(module, "Position")
    .def(pybind11::init<int, int>())
    .def_readwrite("x", &Position::x)
    .def_readwrite("y", &Position::y);

  pybind11::enum_<Action>(module, "Action")
    .value("up", Action::UP)
    .value("down", Action::DOWN)
    .value("left", Action::LEFT)
    .value("right", Action::RIGHT)
    .value("nothing", Action::NOTHING)
    .value("bomb", Action::BOMB);

  pybind11::enum_<EntityType>(module, "Item")
    .value("empty", EntityType::EMPTY)
    .value("box", EntityType::BOX)
    .value("brick", EntityType::BRICK)
    .value("bomb", EntityType::BOMB)
    .value("fire", EntityType::FIRE)
    .value("future_fire", EntityType::FUTURE_FIRE)
    .value("player", EntityType::PLAYER)
    .value("bonus", EntityType::BONUS);
}
