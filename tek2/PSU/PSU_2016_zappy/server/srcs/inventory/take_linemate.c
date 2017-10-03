/*
** take_linemate.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/inventory/take_linemate.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sun Jun 25 22:31:06 2017 Antoine FORET
** Last update Sun Jun 25 22:31:06 2017 Antoine FORET
*/

#include	"inventory.h"

void		inventory_take_linemate(t_inventory *self)
{
  self->linemate += 1;
}