/*
** Sprite.cpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/sources/drawable/Sprite.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Thu Jun 22 09:59:49 2017 Vincent DUSAUTOIR
** Last update Thu Jun 22 09:59:49 2017 Vincent DUSAUTOIR
*/

#include <managers/Engine.hpp>
#include <utils/Error.hpp>
#include <iostream>
#include "drawable/Sprite.hpp"

zappy::Sprite::Sprite(const std::string &name, const zappy::Size &size, const zappy::Position &pos) : _size(size), _pos(pos), _scale(1, 1), _sprite(0), _orientation(0), _color(255, 255, 255, 255){
  this->setTexture(name);
}

zappy::Sprite::~Sprite() {

}

sf::Drawable &zappy::Sprite::get() {
  this->_drawable.setTexture(*this->_texture);
  this->_drawable.setTextureRect(sf::IntRect(this->getSize().width * this->_orientation, this->getSize().length * this->_sprite, this->getSize().width, this->getSize().length));
  this->_drawable.setPosition(this->_pos.inSfml());
  this->_drawable.setScale(this->_scale.inSfml());
  this->_drawable.setColor(this->_color.inSfml());
  return this->_drawable;
}

void zappy::Sprite::setPosition(const zappy::Position &pos) {
  this->_pos = pos;
}

void zappy::Sprite::setTexture(const std::string &name) {
  this->_texture = Engine::get().getRessourcesManager().getTexture(name).get();
}

void zappy::Sprite::setSize(const zappy::Size &size) {
  this->_size = size;
}

const zappy::Position &zappy::Sprite::getPosition() const {
  return this->_pos;
}

const zappy::Size &zappy::Sprite::getSize() const {
  return this->_size;
}

void zappy::Sprite::setScale(const zappy::Size &size) {
  this->_scale = size;
}

const zappy::Size &zappy::Sprite::getScale() const {
  return this->_scale;
}

bool zappy::Sprite::setSprite(const size_t &sprite) {
  Size size(this->_texture->getSize().x, this->_texture->getSize().y);

  if (sprite >= size.length / this->_size.length) {
    this->_sprite = 0;
    return false;
  }
  this->_sprite = sprite;
  return true;
}

void zappy::Sprite::nextSprite() {
  this->setSprite(this->_sprite + 1);
}

void zappy::Sprite::setOrientation(const size_t &orientation) {
  this->_orientation = orientation;
}

void zappy::Sprite::setColor(const zappy::Color &color) {
  this->_color = color;
}
