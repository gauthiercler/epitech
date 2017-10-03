/*
** tick.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/player/tick.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Mon Jun 26 15:08:25 2017 Montagne Valentin
** Last update Mon Jun 26 15:08:25 2017 Montagne Valentin
*/

#include			<stdio.h>
#include			"player.h"

static void			die(t_player *self)
{
  self->send(self, "dead\n");
  self->dead = true;
}

bool				player_tick(t_player *self,
						float nb_tick)
{
  if (self->command_list->size(self->command_list) > 0)
    self->tick_stack += nb_tick;
  else
    self->tick_stack = 0;
  self->hungry += nb_tick;
  if (self->hungry >= HUNGRY)
  {
    self->change = true;
    self->hungry = (int)self->hungry % HUNGRY;
    if (!self->drop(self, EO_FOOD))
      die(self);
  }
  return (true);
}
