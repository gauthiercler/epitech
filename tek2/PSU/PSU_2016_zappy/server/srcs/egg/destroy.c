/*
** destroy.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/egg/destroy.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 24 19:14:49 2017 Antoine FORET
** Last update Sat Jun 24 19:14:49 2017 Antoine FORET
*/

#include	<malloc.h>
#include	"egg.h"

void		egg_destroy(t_egg *self)
{
  free(self);
}