/*
** Tiles.hpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/includes/game/Tiles.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Thu Jun 22 08:57:09 2017 Vincent DUSAUTOIR
** Last update Thu Jun 22 08:57:09 2017 Vincent DUSAUTOIR
*/

#ifndef PSU_2016_ZAPPY_TILES_HPP
#define PSU_2016_ZAPPY_TILES_HPP

#include <chrono>
#include "drawable/Sprite.hpp"
#include "AEntity.hpp"
#include "Thystame.hpp"
#include "Linemate.hpp"
#include "Deraumere.hpp"
#include "Sibur.hpp"
#include "Mendiane.hpp"
#include "Phiras.hpp"
#include "Food.hpp"
#include "Incantation.hpp"

namespace	zappy{
  class			Tiles : public AEntity{
    Position		_pos;
    Sprite		_sprite;
    Food		_food;
    Linemate		_linemate;
    Deraumere		_deraumere;
    Sibur		_sibur;
    Mendiane		_mendiane;
    Phiras		_phiras;
    Thystame		_thystame;
    Incantation		_incantation;
    std::chrono::time_point<std::chrono::system_clock> _last;
    std::vector<std::reference_wrapper<Material>> _materials;
    bool		_display;

  public:
    Tiles(const Position &pos);
    ~Tiles();

    virtual void update();
    virtual void render(const Position &offset, const Size &scale);
    virtual void renderMaterial();
    void	 renderSelected();
    virtual void setDisplay(bool display);
    virtual void setMaterials(size_t food, size_t linemate, size_t deraumere, size_t sibur, size_t mendiane, size_t phiras, size_t thystame);
    void	 setIncantation(size_t level);
    void	 endIncantation(bool success);
  };
}

#endif //PSU_2016_ZAPPY_TILES_HPP
