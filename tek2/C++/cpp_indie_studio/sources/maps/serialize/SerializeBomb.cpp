/*
** SerializeBomb.cpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/SerializeBomb.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  dim. juin 18 10:56:24 2017 Anthony LECLERC
** Last update dim. juin 18 10:56:24 2017 Anthony LECLERC
*/

#include 	"maps/Serialize.hpp"


indie::SerializeBomb::Out &
indie::SerializeBomb::serialize(Out& out, In const &data) const {
  out = Out();

  out.pos = data.getSceneNode()->getPosition();
  out.power = data.getPower();
  out.timer = data.getTimer();
  out.type = 0;
  return out;
}

indie::SerializeBomb::Out &&
indie::SerializeBomb::serialize(In const& data) const {
  Out out;
  return std::move(serialize(out, data));
}
