/*
** disconnect.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/player/disconnect.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 29 14:17:47 2017 Antoine FORET
** Last update Thu Jun 29 14:17:47 2017 Antoine FORET
*/

#include	"player.h"

void		player_disconnect(t_player *self)
{
  self->socket->disconnect(self->socket);
}