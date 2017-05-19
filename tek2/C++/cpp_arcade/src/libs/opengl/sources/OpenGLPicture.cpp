/*
** OpenGLPicture.cpp for cpp_arcade in /home/gogo/rendu/tek2/cpp_arcade/src/libs/opengl/OpenGLPicture.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Mar 19 18:58:34 2017 Gauthier Cler
** Last update Sat Mar 25 23:30:35 2017 Gauthier Cler
*/

#include <SFML/Graphics/Transformable.hpp>
#include <iostream>
#include <memory>
#include "OpenGLPicture.hpp"

arcade::OpenGLPicture::OpenGLPicture() : _loaded(false), _rotation(0), _scale({0, 0}),
					 _positions(pos(0, 0)), _size(pos(0, 0)), _color(rgb(255, 0, 0, 0)) {
}

arcade::OpenGLPicture::~OpenGLPicture() {

}

bool arcade::OpenGLPicture::load(const std::string &path) {

  if (!this->_image.loadFromFile(path))
    return false;
  this->_loaded = true;
  return true;
}

bool arcade::OpenGLPicture::rotate(float angle) {
  this->_rotation = angle;
  return true;
}

bool arcade::OpenGLPicture::setScale(float scaleX, float scaleY) {
  this->_scale = {scaleX, scaleY};
  return true;
}

bool arcade::OpenGLPicture::isLoaded() const {
  return this->_loaded;
}

float arcade::OpenGLPicture::getRotate() const {
  return this->_rotation;
}

float arcade::OpenGLPicture::getXScale() const {
  return this->_scale.x;
}

float arcade::OpenGLPicture::getYScale() const {
  return this->_scale.y;
}

bool
arcade::OpenGLPicture::setInnerPos(const arcade::pos &positions, uint64_t width,
				   uint64_t height) {

  this->_size = pos(width, height);
  this->_positions = positions;
  return true;
}

sf::Texture arcade::OpenGLPicture::getImage() const {
  return this->_image;
}

void arcade::OpenGLPicture::setColor(const arcade::rgb &color) {
  this->_color = color;
}

const arcade::rgb &arcade::OpenGLPicture::getColor() const {
  return this->_color;
}

const arcade::pos &arcade::OpenGLPicture::getSize() const {
  return *std::make_shared<arcade::pos>(this->_size.x, this->_size.y);
}
