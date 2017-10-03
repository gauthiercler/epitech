/*
** send_player_position.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/graph_client/send_player_position.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Wed Jun 28 13:37:22 2017 Montagne Valentin
** Last update Wed Jun 28 13:37:23 2017 Montagne Valentin
*/

#include		<stdio.h>
#include		<string.h>
#include		"graph_client.h"

bool			send_player_position(t_graph_client *self,
						 t_player *player)
{
  char			msg[MAXBUFFSIZE_PLAYERPOS];

  if (snprintf(msg, MAXBUFFSIZE_PLAYERPOS, "ppo %d %d %d %d\n",
	       player->id, player->position.x,
	       player->position.y, player->direction) == -1)
    return (false);
  return (self->send(self, msg));
}