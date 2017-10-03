/*
** tick.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/egg/tick.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 24 19:13:15 2017 Antoine FORET
** Last update Sat Jun 24 19:13:15 2017 Antoine FORET
*/

#include	"egg.h"

void		egg_tick(t_egg *self, float nb_tick)
{
  if (self->time_hatching < nb_tick)
    self->time_hatching = 0;
  else
    self->time_hatching -= nb_tick;
}