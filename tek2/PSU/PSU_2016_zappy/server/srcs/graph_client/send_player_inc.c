/*
** send_player_inc.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/graph_client/send_player_inc.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Wed Jun 28 15:08:51 2017 Montagne Valentin
** Last update Wed Jun 28 15:08:51 2017 Montagne Valentin
*/

#include		<string.h>
#include		<stdio.h>
#include		"graph_client.h"

bool			send_player_inc(t_graph_client *self,
					    t_player *player)
{
  char			msg[MAXBUFFSIZE_PLAYERINC];
  int			pos;

  pos = sprintf(msg, "pic %d %d %d\n",
		player->position.x, player->position.y,
		player->level);
  if (pos == -1)
    return (false);
  return (self->client->send(self->client, msg, strlen(msg), true) != -1);
}