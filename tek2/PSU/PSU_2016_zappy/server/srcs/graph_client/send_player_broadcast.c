/*
** send_player_broadcast.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/graph_client/send_player_broadcast.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Wed Jun 28 15:05:20 2017 Montagne Valentin
** Last update Wed Jun 28 15:05:22 2017 Montagne Valentin
*/

#include		<string.h>
#include		<stdio.h>
#include		"graph_client.h"

bool			send_player_broadcast(t_graph_client *self,
						  unsigned int id,
						  char *msg)
{
  char			data[MAXBUFFSIZE_PLAYERBROAD + strlen(msg)];

  if (sprintf(data, "pbc #%d %s", id, msg) == -1)
    return (false);
  return (self->client->send(self->client, data, strlen(data), true) != -1);
}