/*
** Color.cpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/sources/utils/Color.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Jun 20 23:31:17 2017 Vincent DUSAUTOIR
** Last update Tue Jun 20 23:31:17 2017 Vincent DUSAUTOIR
*/

#include "utils/Color.hpp"

zappy::Color::Color(unsigned char r, unsigned char g, unsigned char b,
		    unsigned char a) : r(r), g(g), b(b), a(a) {

}

zappy::Color::~Color() {

}

sf::Color zappy::Color::inSfml() const {
  return sf::Color(this->r, this->g, this->b, this->a);
}
