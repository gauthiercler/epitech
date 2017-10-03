/*
** destroy.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/inventory/destroy.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sun Jun 25 22:48:48 2017 Antoine FORET
** Last update Sun Jun 25 22:48:48 2017 Antoine FORET
*/

#include	<malloc.h>
#include	"inventory.h"

void		inventory_destroy(t_inventory *self)
{
  free(self);
}