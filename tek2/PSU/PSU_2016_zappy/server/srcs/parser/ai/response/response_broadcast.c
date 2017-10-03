/*
** response_broadcast.c for PSU_2016_zappy in /home/clement/Documents/rendu/c_reseau/PSU_2016_zappy/server/srcs/parser/ai/response/response_broadcast.c
**
** Made by Clement Nancelle
** Login   <clement.nancelle@epitech.eu>
**
** Started on  Fri Jun 30 16:31:50 2017 Clement Nancelle
** Last update Fri Jun 30 16:31:50 2017 Clement Nancelle
*/

#include		<stdio.h>
#include		"parse_stream.h"

static bool		send_to_player(t_player *player, void **params)
{
  char			buff[MAXBUFFSIZE_BROADCAST];
  t_player		*src;
  t_server		*server;
  int			direction;
  t_cardinal		real_direction;

  server = params[0];
  src = params[1];
  real_direction = server->map->direction(server->map,
					  &src->position, &player->position);
  direction = player->get_cardinal(player, real_direction);
  snprintf(buff, MAXBUFFSIZE_BROADCAST, "message %d, %s\n", direction,
	   (char *)(src->command_list->first(src->command_list)->params));
  if (src == player)
    return (player->send(player, "ok\n"));
  else
    return (player->send(player, buff));
}

static bool		send_to_gfx(t_graph_client *gfx, const char *message)
{
  return (gfx->send(gfx, message));
}

bool			response_broadcast(t_player *player, t_server *server)
{
  char			buff[MAXBUFFSIZE_BROADCAST];
  void			*data[2];

  snprintf(buff, MAXBUFFSIZE_BROADCAST, "pbc %d %s\n", player->id,
	   (char *)(player->command_list->first
	     (player->command_list)->params));
  data[0] = server;
  data[1] = player;
  server->gfx->apply(server->gfx, (t_list_action)(send_to_gfx), buff);
  return (server->players->apply(server->players,
				 (t_list_action)(send_to_player), &data));
}