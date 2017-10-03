/*
** drop_thystame.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/inventory/drop_thystame.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sun Jun 25 22:47:58 2017 Antoine FORET
** Last update Sun Jun 25 22:47:58 2017 Antoine FORET
*/

#include	"inventory.h"

bool		inventory_drop_thystame(t_inventory *self)
{
  if (self->thystame == 0)
    return (false);
  self->thystame -= 1;
  return (true);
}