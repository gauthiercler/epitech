/*
** send_egg_open.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/graph_client/send_egg_open.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Wed Jun 28 15:58:31 2017 Montagne Valentin
** Last update Wed Jun 28 15:58:31 2017 Montagne Valentin
*/

#include		<string.h>
#include		<stdio.h>
#include		"graph_client.h"

bool			send_egg_open(t_graph_client *self,
					  unsigned int egg_id)
{
  char			msg[MAXBUFFSIZE_EGGOPEN];

  if (sprintf(msg, "eex %d\n", egg_id) == -1)
    return (false);
  return (self->client->send(self->client, msg, strlen(msg), true) != -1);
}