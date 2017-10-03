/*
** Size.cpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/sources/utils/Size.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Jun 20 23:47:50 2017 Vincent DUSAUTOIR
** Last update Tue Jun 20 23:47:50 2017 Vincent DUSAUTOIR
*/

#include "utils/Size.hpp"

zappy::Size::Size(double width, double length) : width(width), length(length) {

}

zappy::Size::~Size() {

}

double zappy::Size::getWidth() const {
  return this->width;
}

double zappy::Size::getLength() const {
  return this->length;
}

void zappy::Size::setWidth(double width) {
  this->width = width;
}

void zappy::Size::setLength(double length) {
  this->length = length;
}

sf::Vector2f zappy::Size::inSfml() {
  return sf::Vector2f(this->width, this->length);
}
