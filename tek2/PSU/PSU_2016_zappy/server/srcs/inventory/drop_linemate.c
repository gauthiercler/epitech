/*
** drop_linemate.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/inventory/drop_linemate.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sun Jun 25 22:31:51 2017 Antoine FORET
** Last update Sun Jun 25 22:31:51 2017 Antoine FORET
*/

#include	"inventory.h"

bool		inventory_drop_linemate(t_inventory *self)
{
  if (self->linemate == 0)
    return (false);
  self->linemate -= 1;
  return (true);
}