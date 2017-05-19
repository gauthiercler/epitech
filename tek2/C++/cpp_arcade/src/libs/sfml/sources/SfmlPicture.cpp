/*
** SfmlPicture.cpp for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/src/libs/sfml/sources/SfmlPicture.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Mon Mar 20 09:14:49 2017 Vincent DUSAUTOIR
** Last update Mon Mar 20 09:14:49 2017 Vincent DUSAUTOIR
*/

#include "SfmlPicture.hpp"

arcade::SfmlPicture::SfmlPicture() : _loaded(false), _color(0, 0, 0, 0), _rotate(0), _scale(1, 1) {
}

arcade::SfmlPicture::~SfmlPicture() {
}

bool arcade::SfmlPicture::load(const std::string &path) {
  sf::Vector2u size;
  if (!this->_texture.loadFromFile(path))
    return false;
  size = this->_texture.getSize();
  this->_innerSize.x = size.x;
  this->_innerSize.y = size.y;
  this->_loaded = true;
  return true;
}

bool arcade::SfmlPicture::rotate(float angle) {
  this->_rotate = angle;
  return true;
}

bool arcade::SfmlPicture::setScale(float scale_x, float scale_y) {
  this->_scale = {scale_x, scale_y};
  return true;
}

bool arcade::SfmlPicture::isLoaded() const {
  return this->_loaded;
}

float arcade::SfmlPicture::getRotate() const {
  return this->_rotate;
}

float arcade::SfmlPicture::getXScale() const {
  return this->_scale.first;
}

float arcade::SfmlPicture::getYScale() const {
  return this->_scale.second;
}

bool arcade::SfmlPicture::setInnerPos(const arcade::pos &positions, uint64_t width, uint64_t height) {
  this->_innerSize.x = width;
  this->_innerSize.y = height;
  this->_innerPos.x = positions.x;
  this->_innerPos.y = positions.y;
  return true;
}

void arcade::SfmlPicture::setColor(const arcade::rgb &color) {
  this->_color.argb[0] = color.argb[0];
  this->_color.argb[1] = color.argb[1];
  this->_color.argb[2] = color.argb[2];
  this->_color.argb[3] = color.argb[3];
}

const arcade::rgb &arcade::SfmlPicture::getColor() const {
  return this->_color;
}

sf::Sprite arcade::SfmlPicture::getSprite() const {
  sf::Sprite	sprite;

  sprite.setTexture(this->_texture);
  sprite.setTextureRect(sf::IntRect(this->_innerPos.x, this->_innerPos.y, this->_innerSize.x, this->_innerSize.y));
  sprite.rotate(this->getRotate());
  sprite.scale(this->getXScale(), this->getYScale());
  return sprite;
}

const arcade::pos &arcade::SfmlPicture::getSize() const {
  return this->_innerSize;
}
