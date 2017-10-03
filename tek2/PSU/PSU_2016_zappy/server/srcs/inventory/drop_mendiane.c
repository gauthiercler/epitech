/*
** drop_mendiane.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/inventory/drop_mendiane.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sun Jun 25 22:43:48 2017 Antoine FORET
** Last update Sun Jun 25 22:43:48 2017 Antoine FORET
*/

#include	"inventory.h"

bool		inventory_drop_mendiane(t_inventory *self)
{
  if (self->mendiane == 0)
    return (false);
  self->mendiane -= 1;
  return (true);
}