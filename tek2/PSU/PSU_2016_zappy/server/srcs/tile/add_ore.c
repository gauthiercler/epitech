/*
** add_ore.c for PSU_2016_zappy in /home/clement/Documents/rendu/c_reseau/PSU_2016_zappy/server/srcs/tile/add_ore.c
**
** Made by Clement Nancelle
** Login   <clement.nancelle@epitech.eu>
**
** Started on  Wed Jun 28 16:04:06 2017 Clement Nancelle
** Last update Wed Jun 28 16:04:06 2017 Clement Nancelle
*/

#include					"tile.h"

static const t_inventory_take_handler		inventory_handler[] =
  {
    { EO_FOOD, inventory_take_food },
    { EO_LINEMATE, inventory_take_linemate },
    { EO_DERAUMERE, inventory_take_deraumere },
    { EO_SIBUR, inventory_take_sibur },
    { EO_MENDIANE, inventory_take_mendiane },
    { EO_PHIRAS, inventory_take_phiras },
    { EO_THYSTAME, inventory_take_thystame }
  };

bool						tile_add_ore(t_tile *self,
								 t_ore ore)
{
  unsigned int				idx;

  idx = 0;
  while (idx < INVENTORY_SIZE)
  {
    if (inventory_handler[idx].ore == ore)
      inventory_handler[idx].take(self->inventory);
    idx += 1;
  }
  return (true);
}