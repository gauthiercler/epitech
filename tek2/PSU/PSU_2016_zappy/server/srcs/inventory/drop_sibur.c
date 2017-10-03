/*
** drop_sibur.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/inventory/drop_sibur.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sun Jun 25 22:36:30 2017 Antoine FORET
** Last update Sun Jun 25 22:36:30 2017 Antoine FORET
*/

#include	"inventory.h"

bool		inventory_drop_sibur(t_inventory *self)
{
  if (self->sibur == 0)
    return (false);
  self->sibur -= 1;
  return (true);
}