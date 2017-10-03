/*
** destroy.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/graph_client/destroy.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Wed Jun 28 16:27:02 2017 Montagne Valentin
** Last update Wed Jun 28 16:27:03 2017 Montagne Valentin
*/

#include		<stdlib.h>
#include		"graph_client.h"

void			graph_client_destroy(t_graph_client *self)
{
  if (self->client != NULL)
    self->client->destroy(self->client);
  if (self->input_buffer != NULL)
    self->input_buffer->destroy(self->input_buffer);
  if (self->output_buffer != NULL)
    self->output_buffer->destroy(self->output_buffer);
  free(self);
}