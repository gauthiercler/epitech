/*
** turn.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/player/turn.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Fri Jun 30 13:34:51 2017 Montagne Valentin
** Last update Fri Jun 30 13:34:51 2017 Montagne Valentin
*/

#include		"player.h"

void			player_turn(t_player *self, bool dir)
{
  if (dir == PLAYER_RIGHT)
    self->direction += 1;
  else
    self->direction -= 1;
  if (self->direction >= NB_DIRECTION)
    self->direction %= NB_DIRECTION;
  else if ((int)self->direction < 0)
    self->direction += NB_DIRECTION;
}