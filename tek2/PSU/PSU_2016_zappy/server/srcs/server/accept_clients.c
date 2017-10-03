/*
** accept_clients.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/server/accept_clients.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 28 22:49:40 2017 Antoine FORET
** Last update Wed Jun 28 22:49:40 2017 Antoine FORET
*/

#include	<stdio.h>
#include <graph_client.h>
#include	"server.h"

static void	accept_ai(t_server *self)
{
  t_client	*client;
  t_player	*player;

  client = self->socket_ai->accept(self->socket_ai);
  if (client == NULL)
  {
    fprintf(stderr, "[ERROR] Failed to accept ai client.\n");
    return ;
  }
  player = new_player(NULL, self->config.id_increment++, NULL, client);
  if (player == NULL)
  {
    fprintf(stderr, "[ERROR] Unable to allocate memory for new player.\n");
    client->destroy(client);
    return ;
  }
  self->connection_queue->push(self->connection_queue, player);
  self->map->add_player(self->map, player, NULL);
  player->send(player, "WELCOME\n");
  fprintf(stderr, "[INFO] Client connected.\n");
}

static void		accept_gfx(t_server *self)
{
  t_client		*client;
  t_graph_client	*gfx_client;

  client = self->socket_gfx->accept(self->socket_gfx);
  if (client == NULL)
  {
    fprintf(stderr, "[WARNING] Unable to accept gfx client.\n");
    return ;
  }
  gfx_client = new_graphical_transmitter(client);
  if (gfx_client == NULL)
  {
    fprintf(stderr, "[ERROR] Unable to allocate memory for gfx client.\n");
    client->destroy(client);
    return ;
  }
  self->gfx->push(self->gfx, gfx_client);
  gfx_client->send_map_size(gfx_client, self->config.width,
			    self->config.height);
  gfx_client->send_time(gfx_client, self->config.frequency);
  gfx_client->send_msg(gfx_client, "Welcome on ZappyServer GAVVAC");
  gfx_client->send_players_spawn(gfx_client, self->players);
  gfx_client->send_eggs_spawn(gfx_client, self->teams);
  gfx_client->send_map(gfx_client, self->map);
}

void		server_accept_clients(t_server *self)
{
  if (self->watcher->can_read(self->watcher, self->socket_ai))
    accept_ai(self);
  if (self->watcher->can_read(self->watcher, self->socket_gfx))
    accept_gfx(self);
}