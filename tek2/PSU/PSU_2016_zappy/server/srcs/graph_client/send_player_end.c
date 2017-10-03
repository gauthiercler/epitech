/*
** send_player_end.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/graph_client/send_player_end.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Wed Jun 28 13:55:18 2017 Montagne Valentin
** Last update Wed Jun 28 13:55:18 2017 Montagne Valentin
*/

#include		<string.h>
#include		<stdio.h>
#include		"graph_client.h"

bool			send_player_end(t_graph_client *self,
					    unsigned int id)
{
  char			msg[MAXBUFFSIZE_PLAYEREND];

  if (sprintf(msg, "pex #%d", id) == -1)
    return (false);
  return (self->client->send(self->client, msg, strlen(msg), true) != -1);
}