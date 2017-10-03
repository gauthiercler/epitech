/*
** server_sync_gfx.c for PSU_2016_zappy in /home/montag_v/rendu/PSU_2016_zappy/server/srcs/server/server_sync_gfx.c
**
** Made by Valentin MONTAGNE
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Sat Jul 01 23:18:53 2017 Valentin MONTAGNE
** Last update Sat Jul 01 23:18:53 2017 Valentin MONTAGNE
*/

#include		"server.h"

static bool		send_sync(t_graph_client *gfx, t_player *player)
{
  return (gfx->send_player_inventory(gfx, player));
}

static bool		apply_sync(t_player *self, t_graph_client_list *gfx)
{
  if (self->change)
  {
    self->change = false;
    return (gfx->apply(gfx, (t_list_action) send_sync, self));
  }
  return (true);
}

void			server_sync_gfx(t_server *self)
{
  self->players->apply(self->players, (t_list_action)apply_sync, self->gfx);
}