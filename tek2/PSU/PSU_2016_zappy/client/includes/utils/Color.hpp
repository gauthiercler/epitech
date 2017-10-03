/*
** Color.hpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/includes/utils/Color.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Jun 20 23:29:30 2017 Vincent DUSAUTOIR
** Last update Tue Jun 20 23:29:30 2017 Vincent DUSAUTOIR
*/

#ifndef PSU_2016_ZAPPY_COLOR_HPP
#define PSU_2016_ZAPPY_COLOR_HPP

#include <SFML/Graphics/Color.hpp>

namespace zappy{
  class		Color{
  public:
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;

    Color(unsigned char r = 0, unsigned char g = 0, unsigned char b = 0, unsigned char a = 255);
    ~Color();
    sf::Color	inSfml() const;
  };

}

#endif //PSU_2016_ZAPPY_COLOR_HPP
