/*
** AMaterial.cpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/sources/game/AMaterial.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Thu Jun 22 16:43:46 2017 Vincent DUSAUTOIR
** Last update Thu Jun 22 16:43:46 2017 Vincent DUSAUTOIR
*/

#include <managers/Engine.hpp>
#include <utils/Random.hpp>
#include "game/Material.hpp"

zappy::Material::Material(zappy::MaterialType type, const std::string &spriteName, const std::string &name) : _type(type), _sprite(spriteName, Size(12, 12)), _nbr(0), _name(name) {
  this->_offset.x = Random::get().generate() % 20;
  this->_offset.y = Random::get().generate() % 20;
}

zappy::Material::~Material() {

}

size_t zappy::Material::get() const {
  return this->_nbr;
}

void zappy::Material::addMaterial(size_t nbr) {
  this->_nbr += nbr;
}

void zappy::Material::removeMaterial(size_t nbr) {
  this->_nbr -= nbr;
}

void zappy::Material::update() {
  this->_sprite.nextSprite();
}

void zappy::Material::operator+=(size_t nbr) {
  this->addMaterial(nbr);
}

void zappy::Material::operator-=(size_t nbr) {
  this->removeMaterial(nbr);
}

const std::string &zappy::Material::getName() const {
  return this->_name;
}

bool zappy::Material::available() {
  return (this->_nbr > 0);
}

void zappy::Material::setPosition(const zappy::Position &pos) {
  this->_pos = pos;
}

void zappy::Material::render(size_t size) {
  std::string		text;

  text = std::string(std::to_string(this->_nbr) + " " + this->_name);
  this->_text.setString(text);
  this->_text.setFont("pixeled", 16);
  this->_text.setColor(Color(236, 240, 241));
  this->_text.setPosition(Position(40, 14 + 28 * size));
  this->_sprite.setScale(Size(2, 2));
  this->_sprite.setPosition(Position(10, 10 + 28 * size));
  Engine::get().getWindowManager().draw(this->_sprite);
  Engine::get().getWindowManager().draw(this->_text);
}

void zappy::Material::render(const zappy::Position &offset,
			     const zappy::Size &scale) {
  Size			scaleSmall;

  scaleSmall = scale;
  scaleSmall.length *= 0.75;
  scaleSmall.width *= 0.75;
  this->_sprite.setScale(scaleSmall);
  this->_sprite.setPosition(Position(this->_pos.x * (this->_sprite.getSize().width + 20) * scale.width + offset.x + (this->_offset.x * scale.width),
				     this->_pos.y * (this->_sprite.getSize().length + 20) * scale.length + offset.y + (this->_offset.y * scale.length)));
  Engine::get().getWindowManager().draw(this->_sprite);
}

void zappy::Material::setMaterial(size_t nbr) {
  this->_nbr = nbr;
}
