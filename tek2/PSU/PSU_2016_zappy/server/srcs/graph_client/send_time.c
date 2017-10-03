/*
** send_time.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/graph_client/send_time.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Wed Jun 28 16:01:56 2017 Montagne Valentin
** Last update Wed Jun 28 16:01:56 2017 Montagne Valentin
*/

#include		<stdio.h>
#include		<string.h>
#include		"graph_client.h"

bool			send_time(t_graph_client *self,
				      unsigned int time)
{
  char			msg[MAXBUFFSIZE_TIME];

  if (snprintf(msg, MAXBUFFSIZE_TIME, "sgt %d\n", time) == -1)
    return (false);
  return (self->send(self, msg));
}