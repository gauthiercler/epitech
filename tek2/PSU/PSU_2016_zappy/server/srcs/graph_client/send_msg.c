/*
** send_msg.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/graph_client/send_msg.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Wed Jun 28 16:10:24 2017 Montagne Valentin
** Last update Wed Jun 28 16:10:24 2017 Montagne Valentin
*/

#include		<stdio.h>
#include		<string.h>
#include		"graph_client.h"

bool			send_msg(t_graph_client *self,
				     char *msg)
{
  char			data[MAXBUFFSIZE_ENDOFGAME];

  if (snprintf(data, MAXBUFFSIZE_ENDOFGAME, "smg %s\n", msg) == -1)
    return (false);
  return (self->send(self, data));
}