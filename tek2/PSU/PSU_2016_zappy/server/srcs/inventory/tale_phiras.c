/*
** tale_phiras.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/inventory/tale_phiras.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sun Jun 25 22:44:35 2017 Antoine FORET
** Last update Sun Jun 25 22:44:35 2017 Antoine FORET
*/

#include	"inventory.h"

void		inventory_take_phiras(t_inventory *self)
{
  self->phiras += 1;
}