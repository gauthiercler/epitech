/*
** clean_players.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/server/clean_players.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 29 09:33:23 2017 Antoine FORET
** Last update Thu Jun 29 09:33:23 2017 Antoine FORET
*/

#include	<stdio.h>
#include	"server.h"

static bool	send_client_disconnected_gfx(t_graph_client *gfx,
						const char *msg)
{
  return (gfx->send(gfx, msg));
}

static bool	remove_player(t_player *player, t_player_cleanout *cleanout)
{
  char		buff[MAXBUFFSIZE_DISCONNECT];

  if (!player->socket->is_connected(player->socket))
  {
    fprintf(stderr, "[INFO] Client disconnected.\n");
    cleanout->list->pop(cleanout->list, player);
    if (player->team != NULL)
      player->team->remove_player(player->team, player);
    cleanout->watcher->untrack(cleanout->watcher, player->socket);
    snprintf(buff, MAXBUFFSIZE_DISCONNECT, "pex %d\n", player->id);
    cleanout->gfx->apply(cleanout->gfx, (t_list_action)
      (send_client_disconnected_gfx), buff);
    player->destroy(player);
  }
  return (true);
}

void		server_clean_players(t_server *self)
{
  t_player_cleanout	cleanout;

  cleanout.watcher = self->watcher;
  cleanout.list = self->players;
  cleanout.gfx = self->gfx;
  self->players->apply(self->players, (t_list_action)
    (remove_player), &cleanout);
  cleanout.list = self->connection_queue;
  self->connection_queue->apply(self->connection_queue, (t_list_action)
    (remove_player), &cleanout);
}