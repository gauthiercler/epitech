/*
** new.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/inventory/new.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 24 19:16:20 2017 Antoine FORET
** Last update Sat Jun 24 19:16:20 2017 Antoine FORET
*/

#include	<malloc.h>
#include	"inventory.h"

static void	inventory_methods(t_inventory *self)
{
  self->take_food = inventory_take_food;
  self->drop_food = inventory_drop_food;
  self->take_linemate = inventory_take_linemate;
  self->drop_linemate = inventory_drop_linemate;
  self->take_deraumere = inventory_take_deraumere;
  self->drop_deraumere = inventory_drop_deraumere;
  self->take_sibur = inventory_take_sibur;
  self->drop_sibur = inventory_drop_sibur;
  self->take_mendiane = inventory_take_mendiane;
  self->drop_mendiane = inventory_drop_mendiane;
  self->take_phiras = inventory_take_phiras;
  self->drop_phiras = inventory_drop_phiras;
  self->take_thystame = inventory_take_thystame;
  self->drop_thystame = inventory_drop_thystame;
  self->destroy = inventory_destroy;
}

static bool	inventory_init(t_inventory *self)
{
  self->food = 0;
  self->thystame = 0;
  self->deraumere = 0;
  self->linemate = 0;
  self->mendiane = 0;
  self->phiras = 0;
  self->sibur = 0;
  return (true);
}

t_inventory	*new_inventory()
{
  t_inventory	*self;

  self = malloc(sizeof(t_inventory));
  if (self == NULL)
    return (NULL);
  inventory_methods(self);
  if (!inventory_init(self))
  {
    self->destroy(self);
    return (NULL);
  }
  return (self);
}