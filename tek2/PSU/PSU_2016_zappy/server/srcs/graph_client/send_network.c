/*
** send_network.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/graph_client/send_network.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Fri Jun 30 13:26:24 2017 Antoine FORET
** Last update Fri Jun 30 13:26:24 2017 Antoine FORET
*/

#include	<stdio.h>
#include	"graph_client.h"

bool		graph_client_send_network(t_graph_client *self)
{
  char		buff[WRITE_SIZE];
  ssize_t	to_write;

  to_write = self->output_buffer->read(
    self->output_buffer, buff, WRITE_SIZE);
  if (to_write == -1)
    return (false);
  if (self->client->send(self->client, buff, (size_t)(to_write), false)
      == SOCKET_ERROR)
    return (false);
  else
    return (true);
}