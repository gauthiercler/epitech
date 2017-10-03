/*
** drop_food.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/inventory/drop_food.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Mon Jun 26 14:39:18 2017 Montagne Valentin
** Last update Mon Jun 26 14:39:18 2017 Montagne Valentin
*/

#include		"inventory.h"

bool			inventory_drop_food(t_inventory *self)
{
  if (self->food == 0)
    return (false);
  self->food -= 1;
  return (true);
}
