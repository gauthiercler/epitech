/*
** Size.hpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/includes/utils/Size.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Jun 20 23:45:28 2017 Vincent DUSAUTOIR
** Last update Tue Jun 20 23:45:28 2017 Vincent DUSAUTOIR
*/

#ifndef PSU_2016_ZAPPY_SIZE_HPP
#define PSU_2016_ZAPPY_SIZE_HPP

#include <SFML/System.hpp>

namespace zappy
{
  class		Size{
  public:
    double	width;
    double	length;

    Size(double width = 0, double length = 0);
    ~Size();

    double	getWidth() const;
    double	getLength() const;
    void		setWidth(double width);
    void		setLength(double length);
    sf::Vector2f	inSfml();
  };
}

#endif //PSU_2016_ZAPPY_SIZE_HPP
