/*
** generate_tracking.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/server/generate_tracking.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 28 16:28:04 2017 Antoine FORET
** Last update Wed Jun 28 16:28:04 2017 Antoine FORET
*/

#include	"server.h"

static bool	add_player(t_player *player, t_socket_watcher *watcher)
{
  int		track_type;

  if (player->socket->is_connected(player->socket))
  {
    track_type = (player->need_write(player) ? TRACK_READ | TRACK_WRITE
					     : TRACK_READ);
    watcher->track(watcher, player->socket, ST_CLIENT, track_type);
  }
  return (true);
}

static bool	add_gfx(t_graph_client *gfx, t_socket_watcher *watcher)
{
  int		track_type;

  if (gfx->client->is_connected(gfx->client))
  {
    track_type = (gfx->need_write(gfx) ? TRACK_READ | TRACK_WRITE
					     : TRACK_READ);
    watcher->track(watcher, gfx->client, ST_CLIENT, track_type);
  }
  return (true);
}

void		server_generate_tracking(t_server *self)
{
  self->watcher->track(self->watcher, self->socket_ai, ST_TCP, TRACK_READ);
  self->watcher->track(self->watcher, self->socket_gfx, ST_TCP, TRACK_READ);
  self->players->apply(self->players, (t_list_action)(add_player),
		       self->watcher);
  self->connection_queue->apply(self->connection_queue,
				(t_list_action)(add_player), self->watcher);
  self->gfx->apply(self->gfx, (t_list_action)(add_gfx), self->watcher);
}