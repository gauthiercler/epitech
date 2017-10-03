/*
** send_map_size.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/graphical_transmitter/send_map_size.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Wed Jun 28 11:06:15 2017 Montagne Valentin
** Last update Wed Jun 28 11:06:15 2017 Montagne Valentin
*/

#include		<string.h>
#include		<stdio.h>
#include                "graph_client.h"

bool			send_map_size(t_graph_client *self,
					  unsigned int x, unsigned int y)
{
  char msg[MAXBUFFSIZE_MAPSIZE];

  if (snprintf(msg, MAXBUFFSIZE_MAPSIZE, "msz %d %d\n", x, y) == -1)
    return (false);
  return (self->send(self, msg));
}