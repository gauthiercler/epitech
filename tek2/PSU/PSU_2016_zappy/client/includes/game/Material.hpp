/*
** AMaterial.hpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/includes/game/AMaterial.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Thu Jun 22 16:28:49 2017 Vincent DUSAUTOIR
** Last update Thu Jun 22 16:28:49 2017 Vincent DUSAUTOIR
*/

#ifndef PSU_2016_ZAPPY_AMATERIAL_HPP
#define PSU_2016_ZAPPY_AMATERIAL_HPP

#include <string>
#include <drawable/Sprite.hpp>
#include <drawable/Text.hpp>
#include "AEntity.hpp"

namespace zappy {
  enum class	MaterialType{
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
  };

  class			Material : public AEntity{
    MaterialType	_type;
  protected:
    Sprite		_sprite;
    Text		_text;
    size_t		_nbr;
    std::string		_name;
    Position		_pos;
    Position		_offset;

  public:
    Material(MaterialType type, const std::string &spriteName, const std::string &name);
    virtual ~Material();

    size_t		get() const;
    const std::string	&getName() const;
    void		addMaterial(size_t nbr);
    void		setMaterial(size_t nbr);
    void		removeMaterial(size_t nbr);
    virtual void	update();
    virtual void	render(const Position &offset, const Size &scale);
    virtual void	render(size_t size);
    bool		available();
    void                operator+=(size_t nbr);
    void                operator-=(size_t nbr);
    void		setPosition(const Position &pos);
  };
}

#endif //PSU_2016_ZAPPY_AMATERIAL_HPP
