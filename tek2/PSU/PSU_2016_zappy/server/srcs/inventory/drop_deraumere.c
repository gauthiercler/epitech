/*
** drop_deraumere.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/inventory/drop_deraumere.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sun Jun 25 22:33:53 2017 Antoine FORET
** Last update Sun Jun 25 22:33:53 2017 Antoine FORET
*/

#include	"inventory.h"

bool		inventory_drop_deraumere(t_inventory *self)
{
  if (self->deraumere == 0)
    return (false);
  self->deraumere -= 1;
  return (true);
}