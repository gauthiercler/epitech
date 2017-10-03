/*
** Rect.cpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/sources/drawable/Rect.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Wed Jun 21 09:54:00 2017 Vincent DUSAUTOIR
** Last update Wed Jun 21 09:54:00 2017 Vincent DUSAUTOIR
*/

#include <managers/Engine.hpp>
#include "drawable/Rect.hpp"

zappy::Rect::Rect(const Size &size, const Position &pos, const Color &color, bool centered) : _size(size), _pos(pos), _color(color), _scale(1, 1), _centered(centered) {

}

zappy::Rect::~Rect() {

}

void zappy::Rect::setColor(const zappy::Color &color) {
  this->_color = color;
}

void zappy::Rect::setPosition(const zappy::Position &pos) {
  this->_pos = pos;
}

void zappy::Rect::setSize(const zappy::Size &size) {
  this->_size = size;
}

const zappy::Size &zappy::Rect::getSize() const {
  return this->_size;
}

zappy::Position zappy::Rect::getPosition() const {
  if (this->_centered)
    return Position(Engine::get().getWindowSize().width / 2 - this->_size.width / 2, this->_pos.y);
  return this->_pos;
}

const zappy::Color &zappy::Rect::getColor() const {
  return this->_color;
}

sf::Drawable &zappy::Rect::get() {
  if (this->_centered)
    this->_drawable.setPosition(Engine::get().getWindowSize().width / 2 - this->_size.width / 2, this->_pos.y);
  else
    this->_drawable.setPosition(this->_pos.inSfml());
  this->_drawable.setScale(this->_scale.inSfml());
  this->_drawable.setSize(this->_size.inSfml());
  this->_drawable.setFillColor(this->_color.inSfml());
  return this->_drawable;
}

void zappy::Rect::setCentered(bool centered) {
  this->_centered = centered;
}

void zappy::Rect::setScale(const zappy::Size &scale) {
  this->_scale = scale;
}
