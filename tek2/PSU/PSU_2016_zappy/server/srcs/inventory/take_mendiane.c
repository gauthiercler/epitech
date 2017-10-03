/*
** take_mendiane.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/inventory/take_mendiane.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sun Jun 25 22:43:21 2017 Antoine FORET
** Last update Sun Jun 25 22:43:21 2017 Antoine FORET
*/

#include	"inventory.h"

void		inventory_take_mendiane(t_inventory *self)
{
  self->mendiane += 1;
}