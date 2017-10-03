/*
** Egg.hpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/includes/game/Egg.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Jun 27 14:43:00 2017 Vincent DUSAUTOIR
** Last update Tue Jun 27 14:43:00 2017 Vincent DUSAUTOIR
*/

#ifndef PSU_2016_ZAPPY_EGG_HPP
#define PSU_2016_ZAPPY_EGG_HPP

#include "drawable/Sprite.hpp"
#include "AEntity.hpp"

namespace zappy {
  class		Egg : public AEntity{
    size_t	_id;
    Position	_pos;
    std::string	_teamName;
    Sprite	_sprite;

  public:
    Egg(size_t id, const Position &pos, const std::string &teamName);
    ~Egg();

    virtual void update();
    virtual void render(const Position &offset, const Size &scale);
    const size_t &getId() const;
    const Position &getPos() const;
    const std::string &getTeamName() const;
  };
}

#endif //PSU_2016_ZAPPY_EGG_HPP
