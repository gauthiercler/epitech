/*
** clean_gfx.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/server/clean_gfx.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Fri Jun 30 21:56:46 2017 Antoine FORET
** Last update Fri Jun 30 21:56:46 2017 Antoine FORET
*/

#include		<stdio.h>
#include		"server.h"

static bool		remove_gfx(t_graph_client *gfx, void **data)
{
  t_socket_watcher	*socket_watcher;
  t_graph_client_list	*list;

  socket_watcher = data[0];
  list = data[1];
  if (!gfx->client->is_connected(gfx->client))
  {
    fprintf(stderr, "[INFO] Gfx client disconnected.\n");
    list->pop(list, gfx);
    socket_watcher->untrack(socket_watcher, gfx->client);
    gfx->destroy(gfx);
  }
  return (true);
}

void			server_clean_gfx(t_server *self)
{
  void			*data[2];

  data[0] = self->watcher;
  data[1] = self->gfx;
  self->gfx->apply(self->gfx, (t_list_action)(remove_gfx), &data);
}