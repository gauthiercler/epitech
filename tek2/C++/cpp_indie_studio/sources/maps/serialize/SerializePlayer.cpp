/*
** SerializePlayer.cpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/SerializePlayer.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  dim. juin 18 10:47:29 2017 Anthony LECLERC
** Last update dim. juin 18 10:47:29 2017 Anthony LECLERC
*/

#include	"maps/Serialize.hpp"

indie::SerializePlayer::Out &
indie::SerializePlayer::serialize(Out& out, In const &data) const {
  out = Out();

  SerializeBomb getbomb;
  for (std::shared_ptr<ABomb> const& bomb : data->getSpawner().getBombs())
  {
    out.bombs.push_back(getbomb.serialize(*bomb));
  }
  out.name = data->getName();
  out.max = data->getSpawner().maxBombs();
  out.speed = data->getSpeed();
  out.proto = getbomb.serialize(data->getSpawner().getProtoype());
  out.pos = data->getSceneNode()->getPosition();
  out.score = data->getScore().getAllScore();
  out.isIA = true;
  out.infos.bind = IADiff::EASY;
  return out;
}

indie::SerializePlayer::Out &&indie::SerializePlayer::serialize(
    indie::SerializePlayer::In const &data) const {
  Out out;
  return std::move(this->serialize(out, data));
}
