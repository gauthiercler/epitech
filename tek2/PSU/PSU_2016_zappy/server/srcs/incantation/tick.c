/*
** tick.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/incantation/tick.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 24 16:46:17 2017 Antoine FORET
** Last update Sat Jun 24 16:46:17 2017 Antoine FORET
*/

#include	"incantation.h"

void		incantation_tick(t_incantation *self, unsigned int nb_tick)
{
  if (nb_tick > self->time_remaining)
    self->time_remaining = 0;
  else
    self->time_remaining -= nb_tick;
}