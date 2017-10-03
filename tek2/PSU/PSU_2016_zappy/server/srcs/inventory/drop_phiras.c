/*
** drop_phiras.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/inventory/drop_phiras.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sun Jun 25 22:45:20 2017 Antoine FORET
** Last update Sun Jun 25 22:45:20 2017 Antoine FORET
*/

#include	"inventory.h"

bool		inventory_drop_phiras(t_inventory *self)
{
  if (self->phiras == 0)
    return (false);
  self->phiras -= 1;
  return (true);
}