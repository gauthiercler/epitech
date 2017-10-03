/*
** Inventory.hpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/sources/game/Inventory.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Sat Jun 24 10:06:42 2017 Vincent DUSAUTOIR
** Last update Sat Jun 24 10:06:42 2017 Vincent DUSAUTOIR
*/

#ifndef PSU_2016_ZAPPY_INVENTORY_HPP
#define PSU_2016_ZAPPY_INVENTORY_HPP

#include "game/Material.hpp"

namespace zappy {
  class		Inventory {
    std::map<MaterialType, size_t>	_inventory;
    std::map<MaterialType, std::string>	_materialSprite;

  public:
    Inventory();
    ~Inventory();

    void	setItemValues(MaterialType type, size_t nbr);
    size_t	get(MaterialType type);
    void	render();
  };
}

#endif //PSU_2016_ZAPPY_INVENTORY_HPP
