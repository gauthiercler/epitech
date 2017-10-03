/*
** IDrawable.hpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/includes/drawable/IDrawable.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Wed Jun 21 09:07:24 2017 Vincent DUSAUTOIR
** Last update Wed Jun 21 09:07:24 2017 Vincent DUSAUTOIR
*/

#ifndef PSU_2016_ZAPPY_IDRAWABLE_HPP
#define PSU_2016_ZAPPY_IDRAWABLE_HPP

#include <SFML/Graphics/Drawable.hpp>

namespace zappy {
  class IDrawable {
  public:
    virtual ~IDrawable(){};
    virtual sf::Drawable	&get() = 0;
  };
}

#endif //PSU_2016_ZAPPY_IDRAWABLE_HPP
