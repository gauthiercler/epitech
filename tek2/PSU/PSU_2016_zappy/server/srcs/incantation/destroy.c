/*
** destroy.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/incantation/destroy.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 24 17:06:10 2017 Antoine FORET
** Last update Sat Jun 24 17:06:10 2017 Antoine FORET
*/

#include	<malloc.h>
#include	"incantation.h"

void		incantation_destroy(t_incantation *self)
{
  free(self);
}