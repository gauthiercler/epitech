/*
** Incantation.cpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/sources/game/Incantation.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Wed Jun 28 20:34:12 2017 Vincent DUSAUTOIR
** Last update Wed Jun 28 20:34:12 2017 Vincent DUSAUTOIR
*/

#include <managers/Engine.hpp>
#include <drawable/Rect.hpp>
#include <drawable/Text.hpp>
#include "game/Incantation.hpp"

zappy::Incantation::Incantation() : _sprite("incantation1", Size(32, 32)), _active(false), _level(0) {
  this->_incantations = {
    {1, "incantation2"},
    {2, "incantation3"},
    {3, "incantation4"},
    {4, "incantation5"},
    {5, "incantation6"},
    {6, "incantation7"},
    {7, "incantation8"}
  };
}

zappy::Incantation::~Incantation() {

}

void zappy::Incantation::setPosition(const zappy::Position &pos) {
  this->_pos = pos;
}

void zappy::Incantation::setLevel(const size_t &level) {
  if (level >= 1 && level <= 7)
    this->_level = level;
  this->_sprite.setTexture(this->_incantations[this->_level]);
}

void zappy::Incantation::setActive(bool active) {
  this->_active = active;
  if (!active)
    this->_sprite.setSprite(0);
  else
    Engine::get().getSoundManager().playSound("incantation");
}

bool zappy::Incantation::isActive() {
  return this->_active;
}

void zappy::Incantation::update() {
  if (this->_active)
    this->_sprite.nextSprite();
}

void zappy::Incantation::render(const zappy::Position &offset,
				const zappy::Size &scale) {
  this->_sprite.setColor(Color(255,255,255, 200));
  this->_sprite.setScale(scale);
  this->_sprite.setPosition(Position(this->_pos.x * this->_sprite.getSize().width * scale.width + offset.x, this->_pos.y * this->_sprite.getSize().length * scale.length + offset.y));
  Engine::get().getWindowManager().draw(this->_sprite);
}

void zappy::Incantation::renderSelected() {

  Rect		rect(Size(124, 130), Position(0, 350), Color(22, 160, 133, 170));
  Text		text(std::to_string(this->_level), "pixeled", 18, true);

  text.setPosition(Position(64, 350 + 70));
  text.setColor(Color(255, 255, 255));
  this->_sprite.setColor(Color(255,255,255, 255));
  this->_sprite.setScale(Size(4, 4));
  this->_sprite.setPosition(Position(0, 350));
  Engine::get().getWindowManager().draw(rect);
  Engine::get().getWindowManager().draw(this->_sprite);
  Engine::get().getWindowManager().draw(text);
}
