/*
** take.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/player/take.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Mon Jun 26 14:24:12 2017 Montagne Valentin
** Last update Mon Jun 26 14:24:12 2017 Montagne Valentin
*/
#include					"player.h"

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

bool					player_take(t_player *self, t_ore ore)
{
  unsigned int				i;

  i = 0;
  while (i < INVENTORY_SIZE)
  {
    if (inventory_handler[i].ore == ore)
      inventory_handler[i].take(self->inventory);
    i += 1;
  }
  return (true);
}
