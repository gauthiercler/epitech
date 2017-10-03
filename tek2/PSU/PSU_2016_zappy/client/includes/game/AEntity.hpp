/*
** AEntity.hpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/includes/game/AEntity.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Thu Jun 22 09:00:38 2017 Vincent DUSAUTOIR
** Last update Thu Jun 22 09:00:38 2017 Vincent DUSAUTOIR
*/

#ifndef PSU_2016_ZAPPY_AENTITY_HPP
#define PSU_2016_ZAPPY_AENTITY_HPP

#include <utils/Position.hpp>
#include <utils/Size.hpp>

namespace		zappy{
  class			AEntity{

  public:
    AEntity();
    virtual ~AEntity();

    virtual void	update() = 0;
    virtual void	render(const Position &offset, const Size &scale) = 0;
  };
}

#endif //PSU_2016_ZAPPY_AENTITY_HPP
