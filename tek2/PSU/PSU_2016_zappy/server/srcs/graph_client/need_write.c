/*
** need_write.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/graph_client/need_write.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Fri Jun 30 13:35:12 2017 Antoine FORET
** Last update Fri Jun 30 13:35:12 2017 Antoine FORET
*/

#include	"graph_client.h"

bool		graph_client_need_write(t_graph_client *self)
{
  return (self->output_buffer->get_remaining_read(self->output_buffer) != 0);
}