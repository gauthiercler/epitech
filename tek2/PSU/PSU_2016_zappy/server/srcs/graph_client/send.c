/*
** send.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/graph_client/send.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Fri Jun 30 13:24:21 2017 Antoine FORET
** Last update Fri Jun 30 13:24:21 2017 Antoine FORET
*/

#include	<memory.h>
#include	"graph_client.h"

bool		graph_client_send(t_graph_client *self, const char *cmd)
{
  size_t	cmd_size;

  cmd_size = strlen(cmd);
  if (cmd_size >
      self->output_buffer->get_remaining_space(self->output_buffer))
    return (false);
  self->output_buffer->write(self->output_buffer, cmd, cmd_size);
  return (true);
}