/*
** Position.hpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/includes/utils/Position.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Jun 20 11:09:27 2017 Vincent DUSAUTOIR
** Last update Tue Jun 20 11:09:28 2017 Vincent DUSAUTOIR
*/

#ifndef PSU_2016_ZAPPY_POSITION_HPP
#define PSU_2016_ZAPPY_POSITION_HPP

#include <SFML/System.hpp>

namespace zappy
{
  class		Position{
  public:
    double	x;
    double	y;

    Position(double x = 0, double y = 0);
    ~Position();

    double	getX() const;
    double	getY() const;
    void		setX(double x);
    void		setY(double y);
    sf::Vector2f	inSfml();
  };

  bool			operator==(const Position &first, const Position &second);

}

#endif //PSU_2016_ZAPPY_POSITION_HPP
