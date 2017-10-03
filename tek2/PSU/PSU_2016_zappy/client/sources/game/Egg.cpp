/*
** Egg.cpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/sources/game/Egg.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Jun 27 14:48:14 2017 Vincent DUSAUTOIR
** Last update Tue Jun 27 14:48:14 2017 Vincent DUSAUTOIR
*/

#include "managers/Engine.hpp"
#include "game/Egg.hpp"

zappy::Egg::Egg(size_t id, const Position &pos, const std::string &teamName) : _id(id), _pos(pos), _teamName(teamName), _sprite("egg", Size(24, 40)) {

}

zappy::Egg::~Egg() {

}

void zappy::Egg::update() {
  this->_sprite.nextSprite();
}

void zappy::Egg::render(const zappy::Position &offset, const zappy::Size &scale) {
  this->_sprite.setScale(Size(scale.width * 0.75, scale.length * 0.75));
  this->_sprite.setPosition(Position(this->_pos.x * 32 * scale.width + offset.x + (20 / 2) * this->_sprite.getScale().width, this->_pos.y * 32 * scale.length + offset.y - 4 * this->_sprite.getScale().length));
  Engine::get().getWindowManager().draw(this->_sprite);
}

const size_t &zappy::Egg::getId() const {
  return this->_id;
}

const zappy::Position &zappy::Egg::getPos() const {
  return this->_pos;
}

const std::string &zappy::Egg::getTeamName() const {
  return this->_teamName;
}
