/*
** Incantation.hpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/includes/game/Incantation.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Wed Jun 28 20:30:39 2017 Vincent DUSAUTOIR
** Last update Wed Jun 28 20:30:39 2017 Vincent DUSAUTOIR
*/

#ifndef PSU_2016_ZAPPY_INCANTATION_HPP
#define PSU_2016_ZAPPY_INCANTATION_HPP

#include <map>
#include "drawable/Sprite.hpp"
#include "AEntity.hpp"

namespace zappy {
  class		Incantation : public AEntity {
    Sprite				_sprite;
    bool				_active;
    Position				_pos;
    size_t				_level;
    std::map<size_t, std::string>	_incantations;

  public:
    Incantation();
    ~Incantation();

    void	setPosition(const Position &pos);
    void	setLevel(const size_t &level);
    void	setActive(bool active);
    bool	isActive();

    virtual void update();

    virtual void render(const Position &offset, const Size &scale);
    void	 renderSelected();
  };
}

#endif //PSU_2016_ZAPPY_INCANTATION_HPP
