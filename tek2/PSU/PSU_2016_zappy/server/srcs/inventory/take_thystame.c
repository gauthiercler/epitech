/*
** take_thystame.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/inventory/take_thystame.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sun Jun 25 22:46:21 2017 Antoine FORET
** Last update Sun Jun 25 22:46:21 2017 Antoine FORET
*/

#include	"inventory.h"

void		inventory_take_thystame(t_inventory *self)
{
  self->thystame += 1;
}