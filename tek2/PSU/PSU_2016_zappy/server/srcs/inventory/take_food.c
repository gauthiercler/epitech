/*
** take_food.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/inventory/take_food.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Mon Jun 26 14:39:57 2017 Montagne Valentin
** Last update Mon Jun 26 14:39:57 2017 Montagne Valentin
*/

#include		"inventory.h"

void			inventory_take_food(t_inventory *self)
{
  self->food += 1;
}