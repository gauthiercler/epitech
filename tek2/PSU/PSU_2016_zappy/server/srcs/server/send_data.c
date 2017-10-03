/*
** send_data.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/server/send_data.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 29 10:37:14 2017 Antoine FORET
** Last update Thu Jun 29 10:37:14 2017 Antoine FORET
*/

#include	"server.h"

static bool	send_player_data(t_player *player, t_socket_watcher *watcher)
{
  if (player->need_write(player) && watcher->can_write(watcher,
						       player->socket))
    player->send_network(player);
  if (player->dead && player->output_buffer->get_remaining_read(
    player->output_buffer) == 0)
    player->disconnect(player);
  return (true);
}

static bool	send_gfx_data(t_graph_client *gfx, t_socket_watcher *watcher)
{
  if (gfx->need_write(gfx) && watcher->can_write(watcher, gfx->client))
    gfx->send_network(gfx);
  return (true);
}

void		server_send_data(t_server *self)
{
  self->players->apply(self->players,
		       (t_list_action)(send_player_data), self->watcher);
  self->connection_queue->apply(self->connection_queue, (t_list_action)
    (send_player_data), self->watcher);
  self->gfx->apply(self->gfx, (t_list_action)(send_gfx_data), self->watcher);
}