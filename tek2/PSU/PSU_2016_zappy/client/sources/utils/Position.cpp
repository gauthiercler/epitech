/*
** Position.cpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/sources/utils/Position.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Jun 20 11:11:39 2017 Vincent DUSAUTOIR
** Last update Tue Jun 20 11:11:39 2017 Vincent DUSAUTOIR
*/

#include "utils/Position.hpp"

zappy::Position::Position(double x, double y) {
  this->setX(x);
  this->setY(y);
}

zappy::Position::~Position() {

}

double zappy::Position::getX() const {
  return this->x;
}

double zappy::Position::getY() const {
  return this->y;
}

void zappy::Position::setX(double x) {
  this->x = x;
}

void zappy::Position::setY(double y) {
  this->y = y;
}

sf::Vector2f zappy::Position::inSfml() {
  return sf::Vector2f(this->x, this->y);
}

bool ::zappy::operator==(const zappy::Position &first,
			const zappy::Position &second) {
  return (first.x == second.x && first.y == second.y);
}
