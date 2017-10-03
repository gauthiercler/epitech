/*
** move.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/player/move.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Mon Jun 26 14:59:20 2017 Montagne Valentin
** Last update Mon Jun 26 14:59:21 2017 Montagne Valentin
*/

#include			"player.h"

void				player_move(t_player *self,
						unsigned int x,
						unsigned int y)
{
  self->position.x = x;
  self->position.y = y;
}
