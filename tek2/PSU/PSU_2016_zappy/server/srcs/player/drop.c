/*
** drop.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/player/drop.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Mon Jun 26 14:50:13 2017 Montagne Valentin
** Last update Mon Jun 26 14:50:13 2017 Montagne Valentin
*/

#include				"player.h"

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

bool					player_drop(t_player *self, t_ore ore)
{
  unsigned int				i;

  i = 0;
  while (i < INVENTORY_SIZE)
  {
    if (inventory_handler[i].ore == ore)
      return (inventory_handler[i].drop(self->inventory));
    i += 1;
  }
  return (false);
}