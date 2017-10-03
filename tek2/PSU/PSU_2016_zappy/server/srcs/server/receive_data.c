/*
** receive_data.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/server/receive_data.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 29 09:07:01 2017 Antoine FORET
** Last update Thu Jun 29 09:07:01 2017 Antoine FORET
*/

#include	"server.h"

static bool	player_receive(t_player *self, t_socket_watcher *watcher)
{
  char		buff[READ_SIZE];
  size_t	to_receive;
  ssize_t	received;

  if (!self->dead && watcher->can_read(watcher, self->socket))
  {
    to_receive = self->input_buffer->get_remaining_space(self->input_buffer);
    if (to_receive > READ_SIZE)
      to_receive = READ_SIZE;
    received = self->socket->receive(self->socket, buff, to_receive, false);
    if (received != SOCKET_ERROR)
      self->input_buffer->write(self->input_buffer, buff, (size_t)(received));
    else
      return (false);
  }
  return (true);
}

static bool	receive_gfx(t_graph_client *gfx, t_socket_watcher *watcher)
{
  char		buff[READ_SIZE];
  size_t	to_receive;
  ssize_t	received;

  if (watcher->can_read(watcher, gfx->client))
  {
    to_receive = gfx->input_buffer->get_remaining_space(gfx->input_buffer);
    if (to_receive > READ_SIZE)
      to_receive = READ_SIZE;
    received = gfx->client->receive(gfx->client, buff, to_receive, false);
    if (received != SOCKET_ERROR)
      gfx->input_buffer->write(gfx->input_buffer, buff, (size_t)(received));
    else
      return (false);
  }
  return (true);
}

void		server_receive_data(t_server *self)
{
  self->players->apply(self->players, (t_list_action)(player_receive),
		       self->watcher);
  self->connection_queue->apply(self->connection_queue, (t_list_action)
    (player_receive), self->watcher);
  self->gfx->apply(self->gfx, (t_list_action)(receive_gfx), self->watcher);
}