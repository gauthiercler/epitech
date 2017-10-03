/*
** remove_ore.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/tile/remove_ore.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 28 13:57:12 2017 Antoine FORET
** Last update Wed Jun 28 13:57:12 2017 Antoine FORET
*/

#include				"tile.h"

static const t_inventory_drop_handler	inventory_handler[] =
  {
    { EO_FOOD, inventory_drop_food },
    { EO_LINEMATE, inventory_drop_linemate },
    { EO_DERAUMERE, inventory_drop_deraumere },
    { EO_SIBUR, inventory_drop_sibur },
    { EO_MENDIANE, inventory_drop_mendiane },
    { EO_PHIRAS, inventory_drop_phiras },
    { EO_THYSTAME, inventory_drop_thystame }
  };

bool					tile_remove_ore(t_tile *self,
							    t_ore ore)
{
  unsigned int				idx;

  idx = 0;
  while (idx < INVENTORY_SIZE)
  {
    if (inventory_handler[idx].ore == ore)
      return (inventory_handler[idx].drop(self->inventory));
    idx += 1;
  }
  return (false);
}