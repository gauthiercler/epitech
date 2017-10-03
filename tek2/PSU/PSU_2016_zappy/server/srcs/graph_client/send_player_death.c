/*
** send_player_death.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/graph_client/send_player_death.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Wed Jun 28 15:51:07 2017 Montagne Valentin
** Last update Wed Jun 28 15:51:09 2017 Montagne Valentin
*/

#include		<string.h>
#include		<stdio.h>
#include		"graph_client.h"

bool			send_player_death(t_graph_client *self,
					      unsigned int id)
{
  char			msg[MAXBUFFSIZE_PLAYERDEATH];

  if (sprintf(msg, "pdi #%d", id) == -1)
    return (false);
  return (self->client->send(self->client, msg, strlen(msg), true) != -1);
}