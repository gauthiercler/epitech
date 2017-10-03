/*
** take_deraumere.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/inventory/take_deraumere.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sun Jun 25 22:33:19 2017 Antoine FORET
** Last update Sun Jun 25 22:33:19 2017 Antoine FORET
*/

#include	"inventory.h"

void		inventory_take_deraumere(t_inventory *self)
{
  self->deraumere += 1;
}